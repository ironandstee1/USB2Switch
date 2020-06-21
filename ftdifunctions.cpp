#include <iostream>
#include "windows.h"
#include "ftdifunctions.h"
#include <QStringList>
#include <string.h>

void ftdiFunctions::consoleRead() {
    ftdiClose();
    ftdiStartup();
    char data_in[12];
    DWORD r_data_len = 12;
    DWORD data_read;
    ftStatus = FT_Read(ftHandle, data_in, r_data_len, &data_read);
    if (ftStatus != FT_OK) std::cout << "ftStatus error\n";
    else std::cout << "Data read(ftdiRead): " << data_in << "\n";
    ftdiClose();
}

void ftdiFunctions::ftdiClose() {
    ftStatus = FT_Close(ftHandle);
}

void ftdiFunctions::ftdiHandshake(QStringList commands) {
    std::string messageComplete = "";
    std::string incomingMessage = "";
    int i = 0;
    if(commands[0].toStdString() == "COMPLETE") {
        for (int j = 0; j < commands.size(); j++) {
            ftdiWrite("COMPLETE");
            incomingMessage = ftdiRead();
            if (incomingMessage == "ERROR") {
                std::cout << "ERROR DETECTED\n";
                return;
            }
            //std::cout << "MSG" << incomingMessage << "\n";
        }
    }
    else if(commands[0].toStdString() == "FLASH") {
        for (int k = 0; k < commands.size(); k++) {
            ftdiWrite("FLASH");
            incomingMessage = ftdiRead();
            if (incomingMessage == "ERROR") {
                std::cout << "ERROR DETECTED\n";
                return;
            }
        }
    }
    else if(commands[0].toStdString() == "EXECUTE") {
        for (int k = 0; k < commands.size(); k++) {
            ftdiWrite("EXECUTE");
            incomingMessage = ftdiRead();
            if (incomingMessage == "ERROR") {
                std::cout << "ERROR DETECTED\n";
                return;
            }
        }
    }
    else if(commands[0].toStdString() == "CLEAR") {
        for (int k = 0; k < commands.size(); k++) {
            ftdiWrite("CLEAR");
            incomingMessage = ftdiRead();

            if(incomingMessage == "CLEARINGMSG"){
                std::cout << incomingMessage << "XXX\n";
            }
            if (incomingMessage == "ERROR") {
                std::cout << "ERROR DETECTED\n";
                return;
            }
        }
    }
    else {
        while (i < commands.size()) {
            incomingMessage = ftdiRead();
            if (incomingMessage == "ERROR") return;
            if(i < 9) messageComplete = "00"+commands[i].toStdString().substr(0,1) + " Complete";
            else if ((i >= 9) && (i < 99)) messageComplete = "0"+commands[i].toStdString().substr(0,2) + " Complete";
            else if (i >= 99) messageComplete = commands[i].toStdString().substr(0,3) + " Complete";

            if (i < 9) ftdiWrite("00"+commands[i].toStdString());
            else if ((i >= 9) && (i < 99)) ftdiWrite("0"+commands[i].toStdString());
            else if (i >= 99) ftdiWrite(commands[i].toStdString());

            std::cout << "Incoming message: " << incomingMessage << " Comparison point: " << messageComplete << "\n";
            if (incomingMessage == messageComplete) {
                ++i;
            }
        }
    }
    ftStatus = FT_Close(ftHandle);
}

std::string ftdiFunctions::ftdiRead() {
    // DO NOT CHANGE YOU ASSHAT
    ftdiClose();
    ftdiStartup();
    char data_in[12];
    DWORD r_data_len = 12;
    DWORD data_read;
    ftStatus = FT_Read(ftHandle, data_in, r_data_len, &data_read);
    if (ftStatus != FT_OK) {
        ftdiClose();
        return "ERROR";
    }
    else {
    //std::cout << "Data read(ftdiRead): " << data_in << "\n";
    std::string fixData(data_in);
    fixData.resize(12);
    ftdiClose();
    return fixData;
    }
}

void ftdiFunctions::ftdiStartup() {
    ftStatus = FT_Open(0, &ftHandle);
    ftStatus |= FT_SetUSBParameters(ftHandle, 4096, 4096); // Set USB transfer sizes
    ftStatus |= FT_SetChars(ftHandle, false, 0, false, 0); // Disable event characters
    ftStatus |= FT_SetTimeouts(ftHandle, 5000, 5000); // Set read/write timeouts to 5 sec
    ftStatus |= FT_SetLatencyTimer(ftHandle, 16); // Latency timer at default 16ms
    ftStatus |= FT_SetFlowControl(ftHandle, FT_FLOW_NONE, 0x11, 0x13); // No flow control
    ftStatus |= FT_SetBaudRate(ftHandle, 9600); // Baud rate = 9600
    ftStatus |= FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_1,
    FT_PARITY_NONE);
}

bool ftdiFunctions::ftdiWrite(std::string outgoingMessage) {
    ftdiClose();
    ftdiStartup();
    char data_out[outgoingMessage.size()];
    strcpy(data_out, outgoingMessage.c_str());
    DWORD w_data_len = outgoingMessage.size();
    DWORD data_written;
    ftStatus = FT_Write(ftHandle, data_out, w_data_len, &data_written);
    std::cout << "Data write(ftdiWrite): " << data_out << "\n";
    if(ftStatus != FT_OK) {
        ftdiClose();
        return false;
    }
    else {
      ftdiClose();
      return true;
    }
    ftdiClose();

}

void ftdiFunctions::sendButton(std::string button) {
    char data_out[12];
    strcpy(data_out, button.c_str());
    DWORD w_data_len = 12;
    DWORD data_written;
    ftStatus = FT_Write(ftHandle, data_out, w_data_len, &data_written);
    std::cout << "Button press: " << button << "\n";
    ftStatus = FT_Close(ftHandle);
}

bool ftdiFunctions::testFtdi() {
    if (ftStatus != FT_OK) {
        printf("ftStatus not ok %d\n", ftStatus); //check for error
        return false;
    }
    else
    {
    char data_out[12] = "Hello World";
    DWORD w_data_len = 12;
    DWORD data_written;
    ftStatus = FT_Write(ftHandle, data_out, w_data_len, &data_written);
    char data_in[12];
    DWORD r_data_len = 12;
    DWORD data_read;
    ftStatus = FT_Read(ftHandle, data_in, r_data_len, &data_read);
    if (ftStatus != FT_OK)
    printf("ftStatus not ok %d\n", ftStatus);
    else
    printf("Data Read: %s\n", data_in);
    }
    return true;
}

void ftdiFunctions::initialHandshake() {
    ftdiClose();
    ftdiStartup();
    char data_in[7] = "";
    DWORD r_data_len = 7;
    DWORD data_read;
    ftStatus = FT_Read(ftHandle, data_in, r_data_len, &data_read);
    if (ftStatus != FT_OK) printf("ftStatus not ok %d\n", ftStatus);
    //ftdiWrite("EEPROM Flash");
    std::cout << "data_in(initial handshake)=" << data_in << "\n";
    ftdiClose();
}

bool ftdiFunctions::validateInt(std::string untestedInt) {
    std::string::const_iterator it = untestedInt.begin();
        while (it != untestedInt.end() && std::isdigit(*it)) ++it;
        return !untestedInt.empty() && it == untestedInt.end();
}

