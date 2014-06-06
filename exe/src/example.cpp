/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief OPC UA Server main.
/// @license GNU GPL
///
/// Distributed under the GNU GPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/gpl.html)
///
#include <iostream>
#include <algorithm>

#include <opc/common/application.h>
#include <opc/common/addons_core/config_file.h>
#include <opc/ua/node.h>

#include <opc/ua/opcuaserver.h>
#include "daemon.h"




using namespace OpcUa;

int main(int argc, char** argv)
{
  OpcUa::OPCUAServer server;
  try
  {
    server.SetLoadCppAddressSpace(true);
    //server.AddAddressSpace("standard_address_space.xml");
    //server.AddAddressSpace("user_address_space.xml");
    server.Start();
    Node root = server.GetRootNode();
    std::cout << "Root node is: " << root << std::endl;
    std::cout << "Childs are: " << std::endl;
    for (Node node: root.GetChildren() )
    {
      std::cout << "    " << node << std::endl;
    }

  }
  catch (const std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown error." << std::endl;
  }
  server.Stop();
  return 0;
}

