//Find in : void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)
	CPythonTextTail& rkTextTail=CPythonTextTail::Instance();
	rkTextTail.RegisterItemTextTail(
		dwVirtualID,
		pItemData->GetName(),
		&pGroundItemInstance->ThingInstance
	);
	
///Change
	rkTextTail.RegisterItemTextTail(dwVirtualID,pItemData->GetName(), &pGroundItemInstance->ThingInstance
#if defined(TOOLTIP_GROUND_ITEM)
		, socket, attr
#endif
	);

//Find
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)

///Change
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber,
#if defined(TOOLTIP_GROUND_ITEM)
	const long* socket, const TPlayerItemAttribute* attr,
#endif
	float x, float y, float z, bool bDrop)
