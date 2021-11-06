#include "Admin.h"

Admin::Admin(string &id, string &pwd) {
    this->id = id;
    this->pwd = pwd;
}

bool Admin::authenticate(string &id_, string &pwd_) {
    return std::equal(this->id.begin(), this->id.end(), id_.begin(), id_.end()) and
    std::equal(this->pwd.begin(), this->pwd.end(), pwd_.begin(), pwd_.end());
}
