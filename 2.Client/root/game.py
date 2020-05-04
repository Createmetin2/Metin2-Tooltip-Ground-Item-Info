#Add
if app.TOOLTIP_GROUND_ITEM:
	import uiToolTip
	
#Find in: def __init__(self, stream):
		self.affectShower = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			self.TooltipGroundItem = None
			self.TooltipData = [0] * 3
			
#Find in: def Close(self):
		self.affectShower = None
		
#Add
		if app.TOOLTIP_GROUND_ITEM:
			if self.TooltipGroundItem:
				self.TooltipGroundItem = None
			self.TooltipData = [0] * 3
			
#Find
		self.interface.BUILD_OnUpdate()
		
#Add
		if app.TOOLTIP_GROUND_ITEM and self.TooltipGroundItem and self.TooltipGroundItem.IsShow():
			(x, y, z) = player.GetMainCharacterPosition()
			if abs(x - self.TooltipData[0]) > player.TOOLTIP_LIMIT_RANGE or abs(y - self.TooltipData[1]) > player.TOOLTIP_LIMIT_RANGE:
				self.ShowItemFromClient(False)
#Find
	def OnPressExitKey(self):
		self.interface.ToggleSystemDialog()
		return TRUE
		
#Add
	if app.TOOLTIP_GROUND_ITEM:
		def ShowItemFromClient(self, open, itemvnum = 0, data = 0, id = 0, owner = ""):		
			if open and not self.TooltipGroundItem:
				self.TooltipGroundItem = uiToolTip.ItemToolTip()
			if open and self.TooltipGroundItem.IsShow() and self.TooltipData[2] == id:
				return
				
			self.TooltipGroundItem.ClearToolTip()
			self.TooltipGroundItem.Hide()
			
			if open:
				(self.TooltipData[0], self.TooltipData[1], z) = player.GetMainCharacterPosition()
				self.TooltipData[2] = id
				pos_x, pos_y = wndMgr.GetMousePosition()
				self.TooltipGroundItem.SetToolTipPosition(pos_x + 5, pos_y - 5)
				self.TooltipGroundItem.AddItemData(itemvnum, data[0], data[1])
				if owner:
					self.TooltipGroundItem.AutoAppendTextLine("Owner: |cffADFF2F{}".format(owner))
					self.TooltipGroundItem.ResizeToolTip()
