#include <mesh-loader/MeshPos.h>
#include <assimp/scene.h>
using namespace meshLoader;
using namespace std;
using namespace glm;

vector<vec3> MeshPos::getPositions()
{
    return positions;
}

void MeshPos::_load(const char *path, int idx)
{
    if (wrappee != nullptr)
        wrappee->_load(path, idx);
    auto mesh = importer.GetScene()->mMeshes[idx];
    for (int i = 0; i < mesh->mNumVertices; ++i)
    {
        positions.push_back(vec3{mesh->mVertices[i].x,
                                 mesh->mVertices[i].y,
                                 mesh->mVertices[i].z});
    }
}
unsigned MeshPos::verticesCount(){
    return positions.size();
}