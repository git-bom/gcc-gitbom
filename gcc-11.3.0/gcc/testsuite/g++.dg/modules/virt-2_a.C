// { dg-module-do run }
// { dg-additional-options -fmodules-ts }
export module foo;
// { dg-module-cmi foo }

export struct Visitor
{
  virtual int Visit ();
};

// Key function explicitly inline (regardless of p1779's state)
// We emit vtables & rtti only in this TU
inline // Yoink!
  int Visitor::Visit ()
{
  return 0;
}

export int Visit (Visitor *v)
{
  return v->Visit ();
}

// Emit here
// { dg-final { scan-assembler {_ZTV7Visitor:} } }
// { dg-final { scan-assembler {_ZTI7Visitor:} } }
// { dg-final { scan-assembler {_ZTS7Visitor:} } }
