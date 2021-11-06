#include "Video.h"

void Video::setCategory(Categories category) {
    Video::category = category;
}

void Video::setTitle(const string &title) {
    Video::title = title;
}

void Video::setRuntime(int runtime) {
    Video::runtime = runtime;
}

void Video::setStars(string *stars) {
    Video::stars = stars;
}

void Video::setDirector(const string &director) {
    Video::director = director;
}

Video::Video(Categories category, string title, int runtime, string stars[2], string director)
        : category(category), title(title), runtime(runtime), director(director) {
    this->stars[0] = stars[0];
    this->stars[1] = stars[1];
}
