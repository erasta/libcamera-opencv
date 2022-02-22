#include "SimpleCam.h"

int main(int argc, char **argv)
{
    SimpleCam cam;
    cam.start();
    cam.go();
    cam.finish();
}