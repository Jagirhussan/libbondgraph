/*******************************************************************************

Copyright (C) The University of Auckland

OpenCOR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenCOR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://gnu.org/licenses>.

*******************************************************************************/
                      
#include "thirdparty/json.hpp"
//metadatastring is generated by cmake, kept out of namespace as vtk_encode_string does not have a option
//to specify namespace
extern const char *metadatastring;
namespace BG {
                    


nlohmann::json getSupportedPhysicalDomainsAndFactoryMethods() {
	nlohmann::json result;
	
	nlohmann::json mtsElectrical;
	mtsElectrical["Capacitance"]="createCapacitor";
	mtsElectrical["Inductance"]="createInductor";
	mtsElectrical["Resistance"]="createResistor";
	mtsElectrical["PotentialSource"]="createConstantVoltageSource";
	mtsElectrical["FlowSource"]="createConstantCurrentSource";
	result["Electrical"] = mtsElectrical;
	
	
	nlohmann::json mtsMechanical;
	mtsMechanical["Capacitance"]="createLinearSpring";
	mtsMechanical["Inductance"]="createMass";
	mtsMechanical["Resistance"]="createLinearDamper";
	mtsMechanical["PotentialSource"]="createConstantForce";
	mtsMechanical["FlowSource"]="createConstantVelocity";
	result["Mechanical"] = mtsMechanical;
	
	
	nlohmann::json mtsHydraulic;
	mtsHydraulic["Capacitance"]="createFluidCompliance";
	mtsHydraulic["Inductance"]="createFluidInertance";
	mtsHydraulic["Resistance"]="createViscousResistance";
	mtsHydraulic["PotentialSource"]="createConstantPressureSource";
	mtsHydraulic["FlowSource"]="createConstantFluidFlowSource";
	result["Hydraulic"] = mtsHydraulic;
	
	
	nlohmann::json mtsBiochemical;
	mtsBiochemical["Reaction"]="createReaction";
	mtsBiochemical["Concentration"]="createConcentration";
	mtsBiochemical["Chemostat"]="createChemostat";
	mtsBiochemical["Flowstat"]="createFlowstat";
	result["Biochemical"] = mtsBiochemical;
	
	
	nlohmann::json mtsGeneric;
	mtsGeneric["PotentialSource"]="createConstantPotentialSource";
	mtsGeneric["FlowSource"]="createConstantFlowSource";
	mtsGeneric["Transformer"]="createTransformer";
	mtsGeneric["Gyrator"]="createGyrator";
	mtsGeneric["OneJunction"]="createOneJunction";
	mtsGeneric["ZeroJunction"]="createZeroJunction";
	result["Generic"] = mtsGeneric;
	
	
	nlohmann::json mtsComposition;
	mtsComposition["PortHamiltonian"]="createPortHamiltonian";
	mtsComposition["UserDefined"]="createUserDefined";
	result["Composition"] = mtsComposition;
	
	result["Domains"] = nlohmann::json::array({"Biochemical","Electrical","Mechanical","Hydraulic","Biochemical","Generic","Composition"});

	result["ElementDefinitions"]  = nlohmann::json::parse(std::string(metadatastring));
	return result;
}
}
