///Add
#if defined(TOOLTIP_GROUND_ITEM)
#include "Tooltip.h"
#include <unordered_map>
#endif

//Find
		void ShowItemTextTail(DWORD VirtualID);
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		const std::unordered_map<DWORD, std::shared_ptr<TooltipData>>& GetTooltipMap() const { return ItemTooltipMap; };
#endif

//Find
		void RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner)
		
///Change
		void RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner
#if defined(TOOLTIP_GROUND_ITEM)
		, const long* socket, const TPlayerItemAttribute* attr
#endif
		);

//Find
		TChatTailMap				m_ChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::unordered_map<DWORD, std::shared_ptr<TooltipData>> ItemTooltipMap;
#endif
