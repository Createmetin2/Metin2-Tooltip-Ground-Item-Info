#Find in: def __init__(self, stream):
		self.affectShower = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			self.tlground = None
			self.TooltipData = [0] * 3
			
#Find in: def Close(self):
		self.affectShower = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			if self.tlground: 
				self.tlground.Hide()
				self.tlground = None
			self.TooltipData = [0] * 3
			
#Find
		self.interface.BUILD_OnUpdate()
		
#Add
		if app.TOOLTIP_GROUND_ITEM and self.tlground:
			TOOLTIP_INFO_LIMIT_RANGE = 500 # change
			(x, y, z) = player.GetMainCharacterPosition()
			if abs(x - self.TooltipData[0]) > TOOLTIP_INFO_LIMIT_RANGE or abs(y - self.TooltipData[1]) > TOOLTIP_INFO_LIMIT_RANGE:
				self.ShowItemFromClient(False)
#Find
	def OnPressExitKey(self):
		self.interface.ToggleSystemDialog()
		return TRUE
		
#Add
	if app.TOOLTIP_GROUND_ITEM:
		def ShowItemFromClient(self, open, itemvnum = 0, data = 0, id = 0, owner = ""):
			import uiToolTip
			if self.tlground:
				if open and self.TooltipData[2] == id:
					return
				else:
					self.tlground.Hide()
					self.tlground = None
			if open:
				pos_x, pos_y = wndMgr.GetMousePosition()
				(self.TooltipData[0], self.TooltipData[1], z) = player.GetMainCharacterPosition()
				self.TooltipData[2] = id
				self.tlground = uiToolTip.ItemToolTip()
				self.tlground.SetToolTipPosition(pos_x + 5, pos_y - 5)
				self.tlground.AddItemData(itemvnum, data[0], data[1])
				if owner:
					self.tlground.AutoAppendTextLine("Owner: |cffADFF2F%s" % owner)
					self.tlground.ResizeToolTip()
