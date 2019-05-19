// Widh Jio
// poscas.cpp

#include <cerrno>

#include "15na.hpp"

using std::cerr;
using std::dec;
using std::endl;
using std::hash;
using std::hex;
using std::size_t;
using std::string;

// 15na program flags
bool wannaSkipKeras = false;
bool wannaDebugPacket = false;
bool wannaDebugWindow = false;

// Websocket server configuration
unsigned short port = 443;
string site = "localhost";

void setPort(unsigned short newPort)
{
  port = newPort;
  $info << "Set ws port to: " << port << endl;
}
void setSite(string newSite)
{
  site = string(newSite);
  $info << "Set ws site to: " << site << endl;
}

// Keras configuration
string model = "model";

// At exit or on error
bool isErrorExit = false;

void _terminate()
{
  if (!isErrorExit && errno != 0)
    terminateP("On-exit error detected");
  else if (!isErrorExit)
    $info << "15na server is ended without any error! Shutting down..." << endl;
  else
    $warn << "Shutting down the program due to the error" << endl;
}
void terminate(string err, bool callPerror, bool dontExit)
{
  isErrorExit = true;
  size_t errHash = hash<string>{}(err);
  $error << red << "(0x" << hex << errHash << ") " << def << dec;
  if (callPerror)
  {
    perror(err.c_str());
  }
  else
  {
    cerr << err << endl;
  }
  if (!dontExit) {
    exit(errHash);
  }
}
void terminateP(char *err)
{
  string str(err);
  terminate(err, true, false);
}
void terminate(char *err)
{
  string str(err);
  terminate(str, false, false);
}
void terminateP(char const *err)
{
  string str(err);
  terminate(str, true, false);
}
void terminate(char const *err)
{
  string str(err);
  terminate(str, false, false);
}
void terminateP(string err)
{
  terminate(err, true, false);
}
void terminate(string err)
{
  terminate(err, false, false);
}
void errorP(string err)
{
  terminate(err, true, true);
}
void errorP(char const* err)
{
  string str(err);
  terminate(str, true, true);
}
void errorP(char* err)
{
  string str(err);
  terminate(str, true, true);
}
