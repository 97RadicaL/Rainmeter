
[Rainmeter]
Update=3000

;---------------------------------------------
; Measures
;---------------------------------------------


[MeasureUptime]
Measure=Uptime
Format="%3!i! hrs, %2!i! mins"
[MeterUptime]
Meter=String
MeasureName=MeasureUptime
FontSize=7
FontColor=198, 201, 195
SolidColor=51, 51, 51,0
Padding=5,5,5,5
AntiAlias=1
StringAlign=Right
Text="%1"
X=(#Scale#*291)
Y=(#Scale#*50)r

[LabelUptime]
Meter=String
MeasureName=MBits
MeterStyle=StyleText | StyleText3
FontSize=7
Text="UPT:"
X=(#Scale#*170)
Y=(#Scale#*4)r


[MWindowsVersion]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=Software\Microsoft\Windows NT\CurrentVersion
RegValue=ProductName
UpdateDivider=-1

 
[MBits]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_BITS
UpdateDivider=-1

[MComputerName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=COMPUTER_NAME
UpdateDivider=-1

[MUserName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

[MCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=-1

[MSite]
Measure=Plugin
Plugin=WebParser
URL=http://www.tell-my-ip.com/index.html
RegExp=(?siU)<td.*>Your IP Address:</td><td>(.*)</td>
FinishAction=[!WriteKeyValue Variables CIP "[MIPAddress]" "#@#Variables.inc"]
UpdateRate=3600

[MIPAddress]
Measure=Plugin
Plugin=WebParser
URL=[MSite]
StringIndex=1
Substitute="":"#CIP#"
UpdateDivider=30

;---------------------------------------------
; Meters
;---------------------------------------------

[LabelMemory]
Meter=String
MeasureName=MDisk1Label
MeterStyle=StyleText
FontSize=7
FontColor=169, 141, 155
SolidColor=51, 51, 51,0
Padding=5,5,5,5
AntiAlias=1
StringAlign=Right
Text="WARD6@SCARECROW"
X=(#Scale#*285)
Y=(#Scale#*12)


[LabelST]
Meter=String
MeterStyle=StyleText | StyleText3
FontSize=7
Text="SYS:"
X=(#Scale#*170)
Y=(#Scale#*30)r

[LabelST]
Meter=String
MeterStyle=StyleText | StyleText3
Text="SYS:"
X=r
Y=(#Scale#*8)r

[ST]
Meter=String
MeasureName=MBits
MeterStyle=StyleText | StyleText3
FontSize=7
StringAlign=Right
Text="Windows X"
X=(#Scale#*285)
Y=r

[LabelCN]
Meter=String
MeterStyle=StyleText | StyleText3
FontSize=7
Text="MEM:"
X=(#Scale#*170)
Y=(#Scale#*44)r

[CN]
Meter=String
MeasureName=MBits
MeterStyle=StyleText | StyleText3
FontSize=7
StringAlign=Right
Text="8GB"
X=(#Scale#*285)
Y=r

[LabelUN]
Meter=String
MeterStyle=StyleText | StyleText3
FontSize=7
Text="CPU:"
X=(#Scale#*170)
Y=(#Scale#*24)r

[UN]
Meter=String
MeasureName=MBits
MeterStyle=StyleText | StyleText3
FontSize=7
StringAlign=Right
Text="i5-7600"
X=(#Scale#*285)
Y=r

[LabelCPUName]
Meter=String
MeterStyle=StyleText | StyleText3
FontSize=7
Text="GPU:"
X=(#Scale#*170)
Y=(#Scale#*24)r

[CPUName]
Meter=String
MeasureName=MBits
MeterStyle=StyleText | StyleText3
FontSize=7
StringAlign=Right
Text="GTX1060 3GB"
X=(#Scale#*285)
Y=r

;---------------------------------------------
; Variables
;---------------------------------------------

[Variables]
PStart=1
PStop=0

;---------------------------------------------
; Measures
;---------------------------------------------

[MPicture]
Measure=Plugin
Plugin=QuotePlugin
PathName=#ImgPath#
FileFilter=*.jpg;*.jpeg;*.png;*.gif
Subfolders=#Subfolder#
Disabled=0
DynamicVariables=1
Group=Slideshow
UpdateDivider=#ImgUpdate#

[MPicName]
Measure=Time
Format=[MPicture]
RegExpSubstitute=1
Substitute="\\(.*)\\":"","^.:":"","...\D$":""
Disabled=0
DynamicVariables=1
Group=Slideshow

[MPlayPause]
Measure=String
String=#PStop#
IfMatch=0
IfMatchAction=[!EnableMeasureGroup Slideshow][!UpdateMeterGroup PStart][!UpdateMeterGroup Slideshow][!Redraw]
IfNotMatchAction=[!DisableMeasureGroup Slideshow][!UpdateMeterGroup PStart][!UpdateMeterGroup Slideshow][!Redraw]
UpdateDivider=5

[Picture]
Meter=Image
MeasureName=MPicture
Group=Slideshow
PreserveAspectRatio=#ImgFit#
GreyScale=#ImgGS#
AntiAlias=1
W=((#Scale#*150)-13)
H=(#Scale#*132)
X=17
Y=(#Scale#*16)

[ContextMenu2]
Meter=Shape
Shape=Rectangle 0,0,(#Scale#*100),(#Scale#*30) | Fill Color #Color2#,50 | StrokeWidth 0
Shape2=Rectangle 1,1,((#Scale#*100)-2),((#Scale#*30)-2) | Fill Color #Color1# | StrokeWidth 0
X=(#Scale#*100)
Y=(#Scale#*80)
Hidden=1
MouseLeaveAction=[!HideMeter ContextMenu2][!HideMeter "Label_Open"][!UpdateMeter *][!Redraw]
LeftMouseUpAction=["[MPicture]"]

[Label_Open]
Meter=String
MeterStyle=StyleText
StringAlign=Center
Text="#OpenPic#"
W=(#Scale#*90)
X=(#Scale#*150)
Y=(#Scale#*89)
Hidden=1

;---------------------------------------------
;---------------------------------------------
