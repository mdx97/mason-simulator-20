#include <fstream>
#include <sstream>
#include "engine/Logger.h"
#include "engine/ResourceManager.h"

// Helper function for getting resource paths.
// Will log an error return an empty string if an appropriate file is not found.
std::string GetResourcePath(const std::string &id, const std::string &extension)
{
    std::ostringstream sstream;
    sstream << "resources/" << id << "." << extension;

    std::fstream fstream;
    fstream.open(sstream.str());

    if (fstream.fail()) {
        std::ostringstream logstream;
        logstream << "Error in ResourceManager::GetResource(): Cannot find file at path '" << sstream.str() << "'";
        Logger::Write(logstream.str());
        return "";
    }

    return sstream.str();
}

// Returns the path for an image resource.
std::string ResourceManager::GetImagePath(const std::string &id)
{
    return GetResourcePath(id, "bmp");
}

// Returns the path for an audio resource.
std::string ResourceManager::GetAudioPath(const std::string &id)
{
    return GetResourcePath(id, "wav");
}
