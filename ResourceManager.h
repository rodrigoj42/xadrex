#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <string>
#include <map>

class ResourceManager
{
private:
    std::map<std::string, SDL_Surface *> surfaceStore;
public:
    SDL_Surface *loadBitmap(std::string filename);
    ~ResourceManager();
};

#endif // RESOURCEMANAGER_H_INCLUDED
