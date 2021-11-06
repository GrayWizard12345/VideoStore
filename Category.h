#ifndef VIDEOSTORE_CATEGORY_H
#define VIDEOSTORE_CATEGORY_H
#include "Video.h"

class Category{
public:

    void printVideos()
    {
        if (current_count == 0)
            std::cout << "No videos in this category yet!";
    }

    Category(Categories name) : name(name) {
        current_count = 0;
        for (int i = 0; i < 3; ++i) {
            videos[i] = nullptr;
        }
    }
    bool addVideo(Video& video){
        if(current_count < 2){
            videos[current_count] = &video;
            current_count++;
            return true;
        }

        std::cout << "Maximum number of videos in the category haas been reached.\n";
        return false;
    }

    bool removeVideo(int index){
        if (index <= current_count and index > -1)
        {
            for (int i = index-1; i < current_count; ++i) {
                if (i+1 < current_count){
                    videos[i] = videos[i+1];
                } else videos[i] = nullptr;
            }
            current_count--;
        }
    }

private:
    Categories name;
    static const int max_videos = 3;
    static constexpr const char* categories[] = {"Action", "Adventure", "Comedy"};
    int current_count;
    Video* videos[];
};

#endif //VIDEOSTORE_CATEGORY_H
