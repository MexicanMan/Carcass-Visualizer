#include "file_load.h"

FileLoad::FileLoad()
{ }

int FileLoad::Load(const char *filename, BaseModel &mdl)
{
    try
    {
        FILE *f = nullptr;
        openFile(f, filename);

        int point_count = getNumPoint(f);
        loadPoints(f, point_count, mdl);

        int edge_count = getNumEdge(f);
        loadEdge(f, edge_count, mdl);

        mdl.setName(filename);

        closeFile(f);
    }
    catch(BaseError *err)
    {
        throw ;
    }

    return 0;
}

void FileLoad::openFile(FILE *&f, const char *filename)
{
    if (!(f = fopen(filename, "r")))
        throw FileError::OpenFileError("in openFile()");
}

int FileLoad::getNumPoint(FILE *f)
{
    int count;
    if (fscanf(f, "%d", &count) != 1)
        throw FileError::ReadFileError("in getNumPoint()");

    return count;
}

void FileLoad::loadPoints(FILE *f, int count, BaseModel &mdl)
{
    for (int i = 0; i < count; i++)
        mdl.addDot(getPoint(f));
}

Point FileLoad::getPoint(FILE *f)
{
    double x, y, z;

    if (feof(f))
        throw FileError::ReadFileError("in getPoint()");
    if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
        throw FileError::ReadFileError("in getPoint()");

    return Point(x, y, z);
}

int FileLoad::getNumEdge(FILE *f)
{
    int count;
    if (fscanf(f, "%d", &count) != 1)
        throw FileError::ReadFileError("in getNumEdge()");

    return count;
}

void FileLoad::loadEdge(FILE *f, int count, BaseModel &mdl)
{
    int start, end;
    for (int i = 0; i < count; i++)
    {
        getEdge(f, start, end);
        mdl.addLine(start, end);
    }
}

void FileLoad::getEdge(FILE *f, int &start, int &end)
{
    if (feof(f))
        throw FileError::ReadFileError("in getEdge()");
    if (fscanf(f, "%d %d", &start, &end) != 2)
        throw FileError::ReadFileError("in getEdge()");
}

void FileLoad::closeFile(FILE *f)
{
    fclose(f);
}
