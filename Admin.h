#ifndef VIDEOSTORE_ADMIN_H
#define VIDEOSTORE_ADMIN_H
#include <string>
using std::string;

class Admin {
private:
    string id;
    string pwd;
public:
    Admin(string& id, string& pwd);
    bool authenticate(string &id, string &pwd);
};


#endif //VIDEOSTORE_ADMIN_H
