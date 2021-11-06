#ifndef VIDEOSTORE_VIDEO_H
#define VIDEOSTORE_VIDEO_H
#include <string>
using std::string;

enum Categories{
    Action, Adventure, Comedy
};

class Video {
public:
    Video(Categories category, string title, int runtime, string stars[], string director);

    Video(Categories category, string title, int runtime, string stars[2], string director);

    void setCategory(Categories category);

    void setTitle(const string &title);

    void setRuntime(int runtime);

    void setStars(string *stars);

    void setDirector(const string &director);

private:
    Categories category;
    string title;
    int runtime;
    string stars[2];
    string director;

};


#endif //VIDEOSTORE_VIDEO_H
