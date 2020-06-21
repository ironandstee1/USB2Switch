#ifndef FTDIFUNCTIONS_H
#define FTDIFUNCTIONS_H

#include "windows.h"
#include "ftd2xx.h"
#include <string>
#include <QStringList>


class ftdiFunctions {

    public:

    /// Reads the console repeatedly and disallows inputs
    void consoleRead();

    /// Closes FTDI connection
    void ftdiClose();

    /// Performs FTDI handshake by sending all commands to
    /// the Arduino and validating that it receives them.
    /// @param commmands The list of commands gained from the script box
    void ftdiHandshake(QStringList commands);

    /// Receives a 12 length string from the Arduino
    /// @return 12 length std::string
    std::string ftdiRead();

    /// Initiates ftdi and starts connection
    void ftdiStartup();

    /// Writes a message of std::string.size() to FTDI chip
    /// @param outgoingMessage Message to be written
    bool ftdiWrite(std::string outgoingMessage);

    /// Performs the initial handshake to verify FTDI to Arduino communication
    void initialHandshake();

    /// Obsolete sending routine used in instant button clicks (will be fixed soon)
    /// @param button Button to be sent
    void sendButton(std::string button);

    /// Performs a test on the FTDI chip when the RXD is connected to TXD
    bool testFtdi();

    /// Validates that the string only contains an int
    /// from https://stackoverflow.com/a/4654718
    bool validateInt(std::string untestedInt);

    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;

};

#endif // FTDIFUNCTIONS_H
