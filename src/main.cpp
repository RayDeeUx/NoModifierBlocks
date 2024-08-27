#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;
std::map<int, std::string> modifierToSetting = { { 2866, "f" }, { 1829, "s" }, { 1859, "h" }, { 1813, "j" }, { 1755, "d" }};
class $modify(MyPlayLayer, PlayLayer) {
	void addObject(GameObject* p0) {
		if (!Mod::get()->getSettingValue<bool>("enabled")) return PlayLayer::addObject(p0);
		int id = p0->m_objectID;
		if (!modifierToSetting.contains(id)) return PlayLayer::addObject(p0);
		if (!Mod::get()->getSettingValue<bool>(modifierToSetting.find(id)->second)) return PlayLayer::addObject(p0);
	}
};