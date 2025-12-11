// Declaration & Initialization
bitset<100> bs, bs1(42); // empty, from decimal
bitset<8> bs2("11001010"); // from binary string

// Set/Reset/Flip
bs.set(), bs.set(5), bs[5] = 1; // set all, set bit 5, direct assignment
bs.reset(), bs.reset(5); // reset all, reset bit 5
bs.flip(), bs.flip(5); // flip all, flip bit 5

// Query
bs.test(5), bs.all(), bs.any(), bs.none(); // test bit, all set, any set, none set
bs.count(), bs.size(); // count set bits, total size

// Bitwise Operations
bitset<8> a("10101010"), b("11001100"), c;
c = a & b, c = a | b, c = a ^ b, c = ~a; // AND, OR, XOR, NOT
c = a << 2, c = a >> 2; // left shift, right shift

// Conversion
bs.to_ulong(), bs.to_ullong(), bs.to_string(); // to unsigned long, unsigned long long, string

// Find Set Bits
bitset<17> BS; BS[1] = BS[7] = 1;
BS._Find_first(); // first set bit (or size() if none)
BS._Find_next(idx); // next set bit after idx (or size() if none)
for(int i = BS._Find_first(); i < BS.size(); i = BS._Find_next(i)) 
    cout << i << endl; // iterate all set bits

// Applications
for(int m = 0; m < (1 << n); m++) bitset<32> bs(m); // subset generation
bool isPow2 = (bs.count() == 1); // check power of 2


