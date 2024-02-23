#include <algorithm>
#include "myRect.h"


using namespace std;

Rect BoundingRect(Rect rect1, Rect rect2) {
    int left = min(rect1.GetMLeft(), rect2.GetMLeft());
    int right = max(rect1.GetMRight(), rect2.GetMRight());
    int top = min(rect1.GetMTop(), rect2.GetMTop());
    int bottom = max(rect1.GetMBottom(), rect2.GetMBottom());


    return Rect(min(left, right), max(left, right), max(top, bottom), min(top, bottom));
}

Rect BoundingRect2(Rect &rect1, Rect &rect2) {
    int left = min(rect1.GetMLeft(), rect2.GetMLeft());
    int right = max(rect1.GetMRight(), rect2.GetMRight());
    int top = min(rect1.GetMTop(), rect2.GetMTop());
    int bottom = max(rect1.GetMBottom(), rect2.GetMBottom());


    return Rect(min(left, right), max(left, right), max(top, bottom), min(top, bottom));
}