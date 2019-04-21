// Widh Jio
// opt.core.cpp

#include "core.hpp"

using std::string;
using std::cout;
using std::endl;

void showHelpMessage() {
  cout << endl;
  cout << bold << "syaa-ap" << def << " [OPTION...] MODEL" << endl;
  cout << endl;
  cout << "[OPTION]" << endl;
  cout << "\t-p=<PORT>, --port=<PORT>   Set specific port which is used in websocket." << endl;
  cout << "\t                           (Default: 11900)" << endl;
  cout << "\t-s=<ADDR>, --site=<ADDR>   Set specific site name which is used in" << endl;
  cout << "\t                           websocket. (Default: localhost)" << endl;
  cout << "\t-http, --use-http          Set websocket to use http protocol instead of" << endl;
  cout << "\t                           https." << endl;
  cout << "\t--skip-keras               Skip loading Keras model. Use dummy model instead." << endl;
  cout << "\t-h, --help                 Show this help message." << endl;
  cout << "\t-v, --version              Show Syaa AP program version." << endl;
  cout << endl;
  cout << "MODEL" << endl;
  cout << "\tPath to the Keras model used in the AP. (e.g. TheGreatModel.json)" << endl;
  cout << endl;
}

void showVersionMessage() {
  $info << bold << "Syaa AP Program " << def << gray << "Version " << $version << def << endl;
}

void core::procFlagOption(string name)
{
  if (name.compare("help") == 0)
  {
    showHelpMessage();
    exit(0);
  }
  else if (name.compare("version") == 0) {
    showVersionMessage();
    exit(0);
  }
  else if (name.compare("skip-keras") == 0) {
    wannaSkipKeras = true;
    $info << "Loading Keras model will be skiped. But you should enter dummy model name. Predictor will answer random values." << endl;
  }
  else if (name.compare("use-http") == 0)
  {
    setProtocol(string("http"));
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
  else if (name.compare("http") == 0) {
    setProtocol(string("http"));
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
