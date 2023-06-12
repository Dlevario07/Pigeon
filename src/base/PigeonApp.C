#include "PigeonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PigeonApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

PigeonApp::PigeonApp(InputParameters parameters) : MooseApp(parameters)
{
  PigeonApp::registerAll(_factory, _action_factory, _syntax);
}

PigeonApp::~PigeonApp() {}

void 
PigeonApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<PigeonApp>(f, af, s);
  Registry::registerObjectsTo(f, {"PigeonApp"});
  Registry::registerActionsTo(af, {"PigeonApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PigeonApp::registerApps()
{
  registerApp(PigeonApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PigeonApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PigeonApp::registerAll(f, af, s);
}
extern "C" void
PigeonApp__registerApps()
{
  PigeonApp::registerApps();
}
