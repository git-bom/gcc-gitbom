// { dg-additional-options "-fmodules-ts -Wno-pedantic" }
module;
# 4 "header" 1
inline void Foo () {}
# 6 "" 2
export module okely.dokely;
// { dg-module-cmi "okely.dokely" }

namespace One {
  namespace Two {
    inline namespace Three
    {
      inline void Foo2 () {}
      
      export inline void Baz2 () __attribute__((used));
      export inline void Baz2 () { Foo (); Foo2 (); }
    }
  }
}

// { dg-final { scan-assembler "_Z3Foov:" } }
// { dg-final { scan-assembler "_ZW5okely6dokelyEN3One3Two5Three4Foo2Ev:" } }
// { dg-final { scan-assembler "_ZN3One3Two5Three4Baz2Ev:" } }
