// { dg-additional-options -fmodules-ts }

import "used-1_b.H";

int main ()
{
  return wrapper (0);
}

// { dg-final { scan-assembler {_Z4frobi:} } }
