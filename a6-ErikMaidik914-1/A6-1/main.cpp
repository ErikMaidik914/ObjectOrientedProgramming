#include <string>
#include"test.h"
#include "ui.h"

using namespace std;

int main()
{
    Tests::testDomain();
    Tests::testRepository();
    Tests::testAservice();
    Tests::testUservice();
    Repository repo;
    Aservice aservice;
    Uservice uservice;
    aservice.initialiseRepository();

    Ui ui = Ui(aservice, uservice);

    ui.run();

    return 0;
}