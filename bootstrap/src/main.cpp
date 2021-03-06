// everything before first `#if 0` and last `#endif` is summarily ignored by cpd compiler!! but we keep the newlines so line numbers match up.
#if 0
{ /* comments */ }
{ /* comments should be braces followed by c++ style comments. later we will attain the ability to infer the outer braces from just the slash star. */ }
{ /* also - we will be able to switch our brace character to parens later depending on language settings. */ }
{ /* also need to provide a tool to switch between those settings so people with different preferences can mutuallly understand each other more easily. */ }
{ /* how about full line comments? */ }
{ // this seems fine. this even works across lines if you remember the close parens. just note that you now cant have braces in your comments without escaping them with }} double braces or something. }

{ // NOTE: only support ascii for now }

{ // possible syntaxes for functions: }
{ #def void func ( ) { } }
{ #def func ( ) : void { } }
{ #def func ( ) { } }
{ #let func = { } } { // applies for the rest of the file ... }

{ // this starts a verbatim c/c++ block }
#else

// parse the thing
#include <iostream>
#include <fstream>
#include <string>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
#include <memory> 
using std::unique_ptr;
using std::string;
using std::cin;
using std::cout;
using std::getline;

static void close_infile(istream *fh) { dynamic_cast<ifstream *>(fh)->close(); }
static void close_outfile(ostream *fh) { dynamic_cast<ofstream *>(fh)->close(); }
template <class T>
static void no_op(T) { }

int main(int argc, const char ** argv) {
    // Context managers are the first thing to tackle. No need for stupid unique ptr business. Just add syntactic sugar so we clean up resources. Not necessarily exception safe either.
    unique_ptr<istream, decltype(&close_infile)> in_fp(nullptr, &no_op<istream *>);
    unique_ptr<ostream, decltype(&close_outfile)> out_fp(nullptr, &no_op<ostream *>);
    // also if statements and how they play with const types.
    if (argc < 2) { // use std in
        in_fp = unique_ptr<istream, decltype(&close_infile)>(&cin, &no_op<istream *>);
        out_fp = unique_ptr<ostream, decltype(&close_outfile)>(&cout, &no_op<ostream *>);
    } else if (argc == 2) { // onnly 1 argument provided: compile .cpd to .cpp in-place
        string fname = argv[1];
        in_fp = unique_ptr<istream, decltype(&close_infile)>(new ifstream(fname.c_str()), &close_infile);
        // replace .cpd with .cpp
        string out_fname = fname.substr(0, fname.length() - 1) + "p";
        out_fp = unique_ptr<ostream, decltype(&close_outfile)>(new ofstream(out_fname.c_str()), &close_outfile);
    } else if (argc == 4) { // in -o out
        const char * fname = argv[1];
        in_fp = unique_ptr<istream, decltype(&close_infile)>(new ifstream(fname), &close_infile);
        // TODO check argv[2] == "-o"
        const char * out_fname = argv[3];
        out_fp = unique_ptr<ostream, decltype(&close_outfile)>(new ofstream(out_fname), &close_outfile);
        //std::cout << "out fname is " << out_fname << std::endl;
    }
    // now start reading lines of file
    string line;
    ostream &out_fh = *out_fp;
    int line_no = -1;
    while (getline(*in_fp, line)) {
        //for ( auto ch : line ) {
        //    if (ch == '(') {
        //        // do
        //    }
        //}
        line_no += 1;
        out_fh << line << "\n";
    }
    
    return 0;
}

// this ends a verbatim c/c++ block
#endif
#if 0
{ // more stuff here }



{ // This ends the parsing
#endif
// everything before first `#if 0` and last `#endif` is summarily ignored by cpd compiler!!

