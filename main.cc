#include <stdio.h>
#include <unistd.h>

#include "noid.h"

class App{
public:
  App();
  ~App();
  void start();
private:
  int mainloop();

  static noid_lst *noids = 0;
};

App::App()
{
};

App::~App()
{
};

void App::start()
{
  mainloop();
};

int App::mainloop()
{
  int b_while = 0;

  int ticks = 0;
  while(b_while == 0)
    {
      ticks++;
      sleep(1);

      if(ticks == 30)
	{
	  b_while = 1;
	}
    }
  return 0;
};

int main(int argc, char** argv)
{
  App *the_main_app = new App();

  the_main_app->start();
};
