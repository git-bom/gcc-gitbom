// PR c++/100006
// { dg-do compile { target c++14 } }

template <class... Ts>
void f() {
  [] { struct S : Ts { }; };	// { dg-error "not expanded" }
}

int main() {
  f<>();
}
