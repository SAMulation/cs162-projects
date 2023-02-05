#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
using namespace std;

class GameObject {
    public:
        GameObject(string, int);
        void setLabel(string l) { label = l; return; }
        void setMaxInstances(int m) { maxInstances = m; return; }
        string getLabel() const { return label; }
        int getMaxInstances() const { return maxInstances; }

    private:
        string label;
        int maxInstances;
};

#endif