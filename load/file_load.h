#ifndef FILE_LOAD_H
#define FILE_LOAD_H
#include "load_strategy.h"

class FileLoad : public LoadStrategy
{
private:
    void openFile(FILE *&f, const char *filename);

    int getNumPoint(FILE *f);
    void loadPoints(FILE *f, int count, BaseModel &mdl);
    Point getPoint(FILE *f);
    int getNumEdge(FILE *f);
    void loadEdge(FILE *f, int count, BaseModel &mdl);
    void getEdge(FILE *f, int &start, int &end);

    void closeFile(FILE *f);
public:
    FileLoad();
    int Load(const char *filename, BaseModel &mdl);
};

#endif // FILE_LOAD_H
