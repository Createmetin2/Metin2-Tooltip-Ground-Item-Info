///Add
#if defined(TOOLTIP_GROUND_ITEM)
void CPythonTextTail::RegisterItemToolTipInfo(unsigned long& id, const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple)
{
	ItemTooltipMap[id] = {std::get<0>(tooltiptuple), std::get<1>(tooltiptuple)};
}
bool CPythonTextTail::GetSocketsAndAttr(unsigned long& id, std::vector<long>& soc, std::vector< TPlayerItemAttribute >& att)
{
	if (ItemTooltipMap.find(id) != ItemTooltipMap.end()) {
		soc = ItemTooltipMap.at(id).sockets;
		att = ItemTooltipMap.at(id).attr;
	}
	return ItemTooltipMap.find(id) != ItemTooltipMap.end();
}
#endif

//Find
	m_ChatTailMap.clear();
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	ItemTooltipMap.clear();
#endif