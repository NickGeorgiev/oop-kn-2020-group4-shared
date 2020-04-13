# include <iostream>
# include <cstring>
# include "Computer/Computer.h"
# include "ComputerShop/ComputerShop.h"


int main () {
    char brand0[] = "T420";
    char brand1[] = "T430s";  
    char brand2[] = "X220t";
    char brand3[] = "X230";
    char brand4[] = "T520";
    char brand5[] = "W530";

    char cpu0[] = "i5 2nd gen";
    char cpu1[] = "i5 3rd gen";
    char cpu2[] = "i7 2nd gen";
    char cpu3[] = "i7 3rd gen";

    char gpu0[] = "intel integrated";
    char gpu1[] = "nvidia quadro";

    char drive0[] = "320 GB HDD";
    char drive1[] = "240 GB SSD";

    Computer pc0(brand0, cpu0, gpu0, drive0, 270.0, 108);
    Computer pc1(brand1, cpu1, gpu0, drive1, 450.0, 24);
    Computer pc2(brand2, cpu0, gpu0, drive0, 300.0, 12);
    Computer pc3(brand3, cpu1, gpu0, drive0, 250.0, 48);
    Computer pc4(brand4, cpu2, gpu0, drive0, 320.0, 24);
    Computer pc5(brand5, cpu3, gpu1, drive1, 600.0, 12);

    Computer pcList[2];
    pcList[0] = pc0;
    pcList[1] = pc1;

    Computer pcListBig[6];
    pcListBig[0] = pc0;
    pcListBig[1] = pc1;
    pcListBig[2] = pc2;
    pcListBig[3] = pc3;
    pcListBig[4] = pc4;
    pcListBig[5] = pc5;


    pc0 = pc0;
    //pc0.print()
    
    pc0 = pc1;
    //pc0.print();

    char nameMg[] = "mg computers sliven";
    ComputerShop mg(nameMg, pcList, 2);
    //mg.printComputers();

    char nameRm[] = "Rmania";
    ComputerShop rMania(nameRm, pcListBig, 6);
    //rMania.printComputers();


    mg.addComputer(pc2);
    mg.buyComputer(pc2);
    //mg.printComputers();

    mg = rMania;
    //mg.printComputers();

        
    
    return 0;
}