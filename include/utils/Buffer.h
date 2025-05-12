#include <list>

#include "implot.h" 

namespace ui::imgui
{
  
// utility structure for realtime plot
struct TimestampedBuffer {
  int MaxSize;
  int Offset;
  ImVector<ImVec2> Data;
  TimestampedBuffer(int max_size = 2000) {
      MaxSize = max_size;
      Offset  = 0;
      Data.reserve(MaxSize);
  }
  void AddPoint(float x, float y) {
      if (Data.size() < MaxSize)
          Data.push_back(ImVec2(x,y));
      else {
          Data[Offset] = ImVec2(x,y);
          Offset =  (Offset + 1) % MaxSize;
      }
  }
  void Erase() {
      if (Data.size() > 0) {
          Data.shrink(0);
          Offset  = 0;
      }
  }

  ImVec2 getFront()
  {
    if (Data.size() < MaxSize)
      return Data.front();
    else
      return Data[Offset];
  }

  ImVec2 getBack()
  {
    if (Data.size() < MaxSize)
    return Data.back();
  else
    return Data[((Offset + 1) % MaxSize)];
  }

};
}
