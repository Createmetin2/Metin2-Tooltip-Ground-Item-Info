//Find
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, {}, {}, {}, x, y, z, bDrop);
#else
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
#endif