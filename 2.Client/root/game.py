#Find in: def __init__(self, stream):
		self.pressNumber = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			self.tlground = None
			self.xTooltipGroundItemStart = 0
			self.yTooltipGroundItemStart = 0
			self.TooltipGroundItemId = 0
			
#Find in: def Close(self):
		self.affectShower = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			if self.tlground: 
				self.tlground.Hide()
				self.tlground = None
			self.xTooltipGroundItemStart = 0
			self.yTooltipGroundItemStart = 0
			self.TooltipGroundItemId = 0
			
#Find
		self.interface.BUILD_OnUpdate()
		
#Add
		if app.TOOLTIP_GROUND_ITEM and self.tlground:
			TOOLTIP_INFO_LIMIT_RANGE = 500 # change
			(x, y, z) = player.GetMainCharacterPosition()
			if abs(x - self.xTooltipGroundItemStart) > TOOLTIP_INFO_LIMIT_RANGE or abs(y - self.yTooltipGroundItemStart) > TOOLTIP_INFO_LIMIT_RANGE:
				self.tlground.Hide()
				self.tlground = None
#Find
	def OnPressExitKey(self):
		self.interface.ToggleSystemDialog()
		return TRUE
		
#Add
	if app.TOOLTIP_GROUND_ITEM:
		def ShowItemFromClient(self, open, itemvnum = 0, metinslot = 0, attrtype = 0, attrval = 0, id = 0):
			import uiToolTip
			if self.tlground:
				if open and self.TooltipGroundItemId = id: # check if same item
					return
				else:
					self.tlground.Hide()
					self.tlground = None
			if open:
				pos_x, pos_y = wndMgr.GetMousePosition()
				(self.xTooltipGroundItemStart, self.yTooltipGroundItemStart, z) = player.GetMainCharacterPosition()
				self.tlground = uiToolTip.ItemToolTip()
				self.tlground.ClearToolTip()
				self.TooltipGroundItemId = id
				attrSlot = []
				for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):	attrSlot.append([attrtype[i], attrval[i]])
				self.tlground.SetToolTipPosition(pos_x + 5, pos_y - 5)
				self.tlground.AddItemData(itemvnum, metinslot, attrSlot)