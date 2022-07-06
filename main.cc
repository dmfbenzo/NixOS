include <stdio.h>
#include <unistd.h>


class App{
public:
  App();
  ~App();
  void start();
private:
  int mainloop();
};

App::App()
{
};

App::~App()
{
};

void App::start()
  {
  };

int App::mainloop()
{
  return 0;
};

int main(int argc, char** argv)
{
  App *the_main_app = new App();

  the_main_app->start();
};
