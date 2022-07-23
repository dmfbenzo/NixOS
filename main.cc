#include "global.h"

#include "noid.h"

#define TICKS 30 // number of seconds kernel runs.


class kernel{

  public:
    kernel();
    ~kernel();
    void start();

  private:
    int mainloop();

    static noid_lst *noids;

};

kernel::kernel()
{
};

kernel::~kernel()
{
};

void kernel::start()
{
  system("rm -rf ./quit.tmp"); // clear quit file

  int p_id =0;
		
  p_id = fork();
  if(p_id == 0)
  {
				//int c_char = 0;
				
				//c_char = getc(stdin);
    system("/bin/sh");
    return ;
  }
  else
  {
    mainloop();
    return;
  }
  return;
};

int kernel::mainloop()
{
  int b_while = 0;

  int ticks = 0;

  while(b_while == 0)
   {
     FILE *t_file;
				 		
    if((t_file = fopen("./quit.tmp", "r") )!=0) // if we could open the file
    {
      fclose(t_file);
      system("rm -rf ./quit.tmp");
				 				
      return 0;
    }
    ticks++;
    sleep(1);

    if(ticks == TICKS)
    {
      b_while = 1;
    }   
  }
  return 0;
};

int main(int argc, char **argv)
{
  kernel *p_kernel;
		
  p_kernel = new kernel();
		
  p_kernel->start();

  delete p_kernel;

}
