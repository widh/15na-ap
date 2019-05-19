// Widh Jio
// opt.core.cpp

#include "core.hpp"

using std::cout;
using std::endl;
using std::string;

void showHelpMessage()
{
  cout << endl;
  cout << bold << "15na-ap" << def << " [OPTION...]" << endl;
  cout << endl;
  cout << "[OPTION]" << endl;
  cout << "\t-p=<PORT>, --port=<PORT>   Set specific port which is used in websocket." << endl;
  cout << "\t                           (Default: 443)" << endl;
  cout << "\t-s=<ADDR>, --site=<ADDR>   Set specific site name which is used in" << endl;
  cout << "\t                           websocket. (Default: localhost)" << endl;
  cout << "\t-h, --help                 Show this help message." << endl;
  cout << "\t-v, --version              Show 15na AP program version." << endl;
  cout << endl;
  cout << "[DEBUG OPTION]" << endl;
  cout << "\t--debug-packet             Show detailed information for each packets." << endl;
  cout << "\t--debug-window             Show detailed process for each windows." << endl;
  cout << endl;
}

void showVersionMessage()
{
  $info << bold << "15na AP Program " << def << gray << "Version " << $version << def << endl;
}

void core::procFlagOption(string name)
{
  if (name.compare("help") == 0)
  {
    showHelpMessage();
    exit(0);
  }
  else if (name.compare("version") == 0)
  {
    showVersionMessage();
    exit(0);
  }
  else if (name.compare("debug-packet") == 0)
  {
    wannaDebugPacket = true;
    $info << "Each received packets will be debugged." << endl;
  }
  else if (name.compare("debug-window") == 0)
  {
    wannaDebugWindow = true;
    $info << "Each windows will be debugged." << endl;
  }
  else
  {
    terminate("Unknown flag name. Is `=` missed?: " + name);
  }
}
void core::procShortFlagOption(string name)
{
  if (name.compare("h") == 0)
  {
    showHelpMessage();
    exit(0);
  }
  else if (name.compare("v") == 0)
  {
    showVersionMessage();
    exit(0);
  }
  else
  {
    terminate("Unknown short flag name. Is `=` missed?: " + name);
  }
}

void core::procDataOption(string name, string value)
{
  if (name.compare("port") == 0)
  {
    setPort((unsigned short)atoi(value.c_str()));
  }
  else if (name.compare("site") == 0)
  {
    setSite(value);
  }
  else
  {
    terminate("Unknown data name: " + name);
  }
}
void core::procShortDataOption(string name, string value)
{
  if (name.compare("p") == 0)
  {
    setPort((unsigned short)atoi(value.c_str()));
  }
  else if (name.compare("s") == 0)
  {
    setSite(value);
  }
  else
  {
    terminate("Unknown short data name: " + name);
  }
}
