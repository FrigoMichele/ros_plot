#ifndef I_DISPOSABLE
#define I_DISPOSABLE
namespace ui
{
  class IDisposable
  {
  public:
    virtual bool initialize();
    virtual bool dispose();
  };
} // namespace ui

#endif