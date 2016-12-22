#include "global.h"
#include <stdio.h>
#include "kernel.h"
#include "constants.h"
#include "stream.h"
#include "compiler.h"
#include "parser.h"
#include <string.h>
#include <unistd.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

Choicepoint qxz = NULL;

void query_complete3(RC result)
{
   if (result == ERROR)
   {
      printf("Error reached the top-level: "); PORTRAY(getException()); printf("\n");
   }
   else if (result == FAIL)
   {
      printf("No more solutions\n");
   }
   else if (result == SUCCESS_WITH_CHOICES)
   {
      //printf("Success! %d\n", result);
      backtrack_query(query_complete3);
   }
}

void query_complete2(RC result)
{
   restore_state(qxz);
   backtrack_query(query_complete3);
}


void query_complete(RC result)
{
   //printf("First goal has exited with %d\n", result);
   if (result == ERROR)
   {
      printf("Error reached the top-level: "); PORTRAY(getException()); printf("\n");
   }
   else if (result == FAIL)
   {
      printf("Top level Failed\n");
   }
   else if (result == SUCCESS_WITH_CHOICES)
   {
      //printf("Success! %d\n", result);
      //qxz = push_state();
      //word w = MAKE_ATOM("run_all_tests");
      //execute_query(w, query_complete2);
      backtrack_query(query_complete3);
   }
   else if (result == SUCCESS)
      printf("Success!\n");
}



EMSCRIPTEN_KEEPALIVE
void do_test(int argc, char** argv)
{
   printf("Consulting...\n");
   int do_inria = 0;
   for (int i = 0; i < argc; i++)
   {
      if (strcmp(argv[i], "--inria") == 0)
         do_inria = 1;
   }
   if (do_inria)
   {
      consult_file("tests/inriasuite/inriasuite.pl");
      chdir("tests/inriasuite");
   }
   else
   {
      consult_file("test.pl");
   }
   printf("Consulted. Running tests...\n");
   /*
   int n = 100000;
   char* buffer = malloc(n);
   for (int i = 0; i < n; i++)
   {
      buffer[i] = 'Q';
      MAKE_NATOM(buffer, i);
   }
   printf("6000 atom test complete\n");
   */
   word w = MAKE_ATOM("run_all_tests");
   execute_query(w, query_complete);
}

/*
  fox(a,b).
  fox(c,d).

  ?-fox(c, X).
*/
