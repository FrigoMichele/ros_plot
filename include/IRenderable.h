#ifndef I_RENDERABLE_H
#define I_RENDERABLE_H
class IRenderable
{
private:
  /* data */
public:
  IRenderable(/* args */);
  ~IRenderable();
  virtual bool render() = 0;
  virtual bool openContext() = 0;
  virtual bool closeContex() = 0;
};

IRenderable::IRenderable(/* args */){}
IRenderable::~IRenderable(){}

#endif