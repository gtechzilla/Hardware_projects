try{var pe={initSw:function(maincallback){if('serviceWorker'in navigator&&_peE.bWSupport&&_peE.sT=='https'){_peD.widget.resetClosedCookie();if(_peD.merchantSettings.sm('workerStatus')){navigator.serviceWorker.register(_peD.merchantSettings.sm('worker'),{scope:"/"}).then(function(registration){pe.pushSub(maincallback);}).catch(function(e){throw e;});}
else{pe.pushSub(maincallback);}}},overlay:{addHtml:function(){if(_peSd.overlay.status){var body=document.getElementsByTagName("BODY")[0];body.insertAdjacentHTML('beforeend',_peSd.overlay.style);body.insertAdjacentHTML('beforeend',_peSd.overlay.html);var oT=_peD.getId("pe-overlay-text");var nc=_peD.getId("pe-pc-notice-text");if(_peE.dT=="mobile"&&_peE.bW.name=='Ucbrowser'&&nc){nc.style.bottom='unset';nc.style.top="0px";}
if(_peE.dT=="desktop"&&oT){if(_peE.bW.name=='Chrome'&&!_peD.getInputUrl('intermediate')){oT.style.left='340px';oT.style.margin='0px';}
if(_peE.bW.name=='Edge'){var oA=_peD.getId("pe-overlay-arrow"),oNT=_peD.getId("pe-pc-notice-text");if(oA){oT.style.display='flex';oT.style.flexDirection='column';oT.style.top='250px';oA.style.transform='rotate(-10deg)';oA.style.order='2';oA.style.marginLeft='auto';}
if(oNT){oNT.style.bottom="unset";oNT.style.top="0px";}}}
else _peD.rvHtml(oT);}
else if(_peSd.site.powBy!=1){var body=document.getElementsByTagName("BODY")[0];body.insertAdjacentHTML('beforeend',_peSd.overlay.powBycss);body.insertAdjacentHTML('beforeend',_peSd.overlay.powByHtml);if(_peD.getInputUrl('intermediate')){var id=_peD.getId("pe-overlay-powby");if(id)id.href="https://www.pushengage.com?utm_source="+_peSd.site.allowedDomain[0]+"&utm_medium=referral&utm_campaign=push_window";}}},hideHtml:function(){if(_peSd.overlay.status){var overlay=_peD.getId("pe-overlay-backdrop");if(overlay)
_peD.rvHtml(overlay);}
else if(_peSd.site.powBy!=1){var overlay=_peD.getId("pe-overlay-powby");if(overlay)
_peD.rvHtml(overlay);}}},apiValid:function(){var valid=true;if(!_peE.checkApiValid||typeof _peD!=='object'||typeof _peSd!=='object'||typeof _peE!=='object'||_peE.sT=='http'||(_peD.deviceToken.cookie()&&Notification.permission=="granted"&&_peD.cookie.get('PushSubscriberStatus')!='UNSUBSCRIBED'))valid=false;if(_peE.refToken)valid=true;return valid;},vapidNotSupportBw:function(){return((_peE.bW.name=="Chrome"&&_peE.bW.version<52)||(_peE.bW.name=="Firefox"&&_peE.bW.version<46))?true:false;},isGcm:function(endpoint){gcm=endpoint.indexOf('android.googleapis.com/gcm')>-1||endpoint.indexOf('updates.push.services.mozilla.com/wpush/v1')>-1
return gcm;},bwUnsubscribe:function(callback){if('serviceWorker'in navigator){_peD.bwUnsubscribeAPI(function(res){pe.subscribe(callback)});}},pushSub:function(maincallback){navigator.serviceWorker.ready.then(function(reg){const subOptions={userVisibleOnly:true};if(!pe.vapidNotSupportBw()){subOptions.applicationServerKey=_peD.publicKey(_peSd.site.vapidPubKey);}
reg.pushManager.subscribe(subOptions).then(function(sub){try{var pe_sub=JSON.parse(JSON.stringify(sub));}
catch(e){return;}
_peD.getDeviceTokenFromEndPoint(pe_sub.endpoint,'init');pe_sub['project_id']=_peSd.gcm.projectId;if(!pe.vapidNotSupportBw()&&!pe.isGcm(pe_sub.endpoint)){pe_sub['vapid_public_key']=_peSd.site.vapidPubKey;}
pe.permissionGranted(pe_sub,maincallback);}).catch(function(e){if(e.message.indexOf('unsubscribe then resubscribe')!=-1)
pe.bwUnsubscribe(maincallback);else
pe.permissionDefault(maincallback);});});},subscribe:function(maincallback){if(!pe.apiValid()){if(_peD.getInputUrl('intermediate')){pe.sendDataToBrowser();}
return;}
_peD.pvtBw(function(pvtBw){if(!pvtBw){if(!_peD.userPerDenied())
switch(_peE.bW.name){case"Safari":if('safari'in window&&'pushNotification'in window.safari){var perD=window.safari.pushNotification.permission(_peSd.safari.pushId);if(perD.permission==='default'||perD.permission==='granted'){_peD.widget.resetClosedCookie();pe.safariPermission(perD,function(perD){if(perD.permission==='denied'){pe.permissionDenied(maincallback);}
else if(perD.permission==='granted')
{pe.overlay.hideHtml();_peD.deviceToken.value=perD.deviceToken;pe.permissionGranted({endpoint:_peD.deviceToken.value,project_id:_peSd.safari.pushId},maincallback);}});}}
break;default:if(Notification.permission=='default'){pe.overlay.addHtml();}
if(pe.vapidNotSupportBw()){var link=document.createElement('link');link.rel='manifest';link.href=_peD.merchantSettings.sm('manifest');document.getElementsByTagName("head")[0].appendChild(link);}
Notification.requestPermission().then(function(status){switch(status){case"default":pe.permissionDefault(maincallback);break;case"denied":pe.permissionDenied(maincallback);break;case"granted":pe.overlay.hideHtml();pe.initSw(maincallback);}});break;}
else{_peD.widget.addBoxHtml(maincallback);}}});},safariPermission:function(permissionData,callback){window.safari.pushNotification.requestPermission(_peSd.api.safariApi,_peSd.safari.pushId,{"app_id":_peSd.site.sK},callback);},permissionDenied:function(maincallback){if(_peE.sT=="https"&&_peE.swSupport==1)
_peD.widget.addHtml(maincallback);pe.overlay.hideHtml();if(_peD.subOptinType()==4){_peD.optinAnalytics({block_1:true,optin_1:true});}
else{_peD.optinAnalytics({allow_1:true,optin_1:true,block_2:true,optin_2:true});}
_peD.cookie.set([['PushSubscriberStatus','DENIED',_peD.cookie.optinHide,'/','cookie'],['peclosed',true,_peE.cookie.optinHide,'/','cookie']]);if(typeof(maincallback)==='function')
maincallback({statuscode:2,status:"DENIED",message:"User denied push notification"});if(_peD.getInputUrl('intermediate')){pe.sendDataToBrowser();}},permissionDefault:function(maincallback){if(_peE.sT=="https"&&_peE.swSupport==1)
_peD.widget.addHtml(maincallback);pe.overlay.hideHtml();if(_peD.subOptinType()==4){_peD.optinAnalytics({close_1:true,optin_1:true});}
else{_peD.optinAnalytics({allow_1:true,optin_1:true,close_2:true,optin_2:true});}
if(_peE.cookie.optinHide!=0)
_peD.cookie.set([['PushSubscriberStatus','CLOSED',_peE.cookie.optinHide,'/','cookie'],['peclosed',true,_peE.cookie.optinHide,'/','cookie']]);if(typeof(maincallback)==='function')
maincallback({statuscode:3,status:"CLOSED",message:"User closed subscription Opt-in"});if(_peD.getInputUrl('intermediate')){pe.sendDataToBrowser();}},permissionGranted:function(subscription,maincallback){if(_peD.getInputUrl('recover_subscriber_from_iframe'))
_peE.refToken=true;_peD.insertFile('js','pushengage-geo',false,function(res){var timezone=_peD.getTimezone();if(typeof peGeoInfo=="undefined")
var geoInfo={geobytestimezone:timezone};else{var geoInfo=peGeoInfo;geoInfo.geobytestimezone=timezone;if(_peSd.site.isEu&&geoInfo.geobytesipaddress){try{var ip=geoInfo.geobytesipaddress;var ip_array=ip.split(".");ip_array.pop();geoInfo.geobytesipaddress=ip_array.join(".");}
catch(e){delete geoInfo.geobytesipaddress;}}}
var data={relApiPath:'/subscriber/add',reqData:{site_id:_peSd.site.sSi,browser_info:{device_type:_peE.bW.name,browser_version:_peE.bW.version,user_agent:navigator.userAgent,language:navigator.language,total_scr_width_height:screen.width+'*'+screen.height,available_scr_width_height:screen.availWidth+'*'+screen.availHeight,colour_resolution:screen.pixelDepth,host:location.host,device:_peE.dT,pe_ref_url:_peE.subUrl},subscription:subscription,subscription_url:_peE.subUrl,geo_info:geoInfo,token_refresh:_peE.refToken}};if(_peSd.subA&&!_peE.refToken){data.reqData.optin_type=_peD.subOptinType();if(_peE.widgetClick)
data.reqData.widget_optin_type=_peD.widget.optinType;}
if(_peSd.welcomeNoti&&_peSd.welcomeNoti.welcome_enabled=="true"&&!_peE.refToken){pe.welcomeNoti(function(res){});}
_peD.sendRequestToServer(data,function(res){var resData=JSON.parse(res);var resObj={statuscode:0,message:"Something went wrong"};if(resData.data&&resData.data.hasOwnProperty('subscriber_hash')&&resData.data.subscriber_hash.length==64){if(!_peE.refToken&&_peD.subOptinType()!=4){_peD.optinAnalytics({allow_2:true,optin_2:true});}
_peD.cookie.set([['peclosed',true,_peD.cookie.global,'/','cookie'],['PushSubscriberID',_peD.deviceToken.value,_peD.cookie.global,'/','local'],['PushSubscriberHash',resData.data.subscriber_hash,_peD.cookie.global,'/','local'],['PushSubscriberStatus','SUBSCRIBED',_peD.cookie.global,'/','cookie'],['PushPersonalNotificationStatus',true,_peD.cookie.global,'/','local'],['SubscriberTimezone',_peD.getTimezone(),_peD.cookie.global,'/','local']]);_peD.cookie.remove([["PushSubscribeWidgetAnalytics","local"]])
if(_peE.sT=="https"&&_peE.swSupport==1&&typeof _pe!="undefined")
_pe.subMangWidget.addHtml();switch(resData.error_code){case 0:resObj.statuscode=1;resObj.status="SUBSCRIBED";resObj.message="User subscribed sucessfully";resObj.subscriber_hash=resData.data.subscriber_hash;resObj.data={geoInfo:pe.formatGeoInfo()};}
if(_peE.subSegment){var segData={relApiPath:'/subscriber/segments/add',reqData:{segment:_peE.subSegment,device_type:_peE.bW.name,device_token:_peD.deviceToken.cookie()}}
_peD.sendRequestToServer(segData,function(res){if(typeof maincallback=='function')maincallback(resObj);if(_peD.getInputUrl('intermediate')){pe.sendDataToBrowser();}});}
else{if(typeof maincallback=='function')maincallback(resObj);if(_peD.getInputUrl('intermediate')){pe.sendDataToBrowser();}}}
else if(_peD.getInputUrl('intermediate')&&window.opener)window.close();});});},welcomeNoti:function(callback){var options={body:_peSd.welcomeNoti.notification_message,tag:_peSd.welcomeNoti.notification_title,icon:_peSd.site.sI,data:_peSd.welcomeNoti.notification_url};if(_peE.bW.name=="Safari"&&Notification.permission==="granted"){var welcomeNoti=new Notification(_peSd.welcomeNoti.notification_title,options);welcomeNoti.onclick=function(event){event.preventDefault();window.open(_peSd.welcomeNoti.notification_url,'_blank');welcomeNoti.close();}
return(typeof callback=='function')?callback(true):true;}
else{navigator.serviceWorker.ready.then(function(registration){if(Notification.permission=='granted')
registration.showNotification(_peSd.welcomeNoti.notification_title,options).then(function(){return(typeof callback=='function')?callback(true):true;});});}},sendDataToBrowser:function(){var state=_peD.cookie.get('PushSubscriberStatus');if(!state){switch(Notification.permission){case"granted":state="SUBSCRIBED";break;case"denied":state="DENIED";break;default:state="CLOSED";}}
var data={PushSubscriberID:_peD.cookie.get('PushSubscriberID'),PushSubscriberHash:_peD.cookie.get('PushSubscriberHash'),state:state,source:"subscribe",postOrigin:"opener",geoInfoData:{geoInfo:pe.formatGeoInfo()},timezone:_peD.cookie.get('SubscriberTimezone')};if(window.opener)
{window.opener.postMessage(JSON.stringify(data),_peE.subUrl);window.close();}
else if(_peD.getInputUrl('recover_subscriber')){data.postOrigin="iframe";parent.postMessage(JSON.stringify(data),'*');}
else if(_peD.getInputUrl('refer'))window.location=_peE.subUrl;else if(_peD.getInputUrl('recover_subscriber_from_iframe')){data.postOrigin="iframe";data.subscriberOrigin="recoverSubscriber";parent.postMessage(JSON.stringify(data),'*');}},formatGeoInfo:function(){return{country:(typeof peGeoInfo!="undefined"&&typeof peGeoInfo.geobytescountry!="undefined")?peGeoInfo.geobytescountry:"",state:(typeof peGeoInfo!="undefined"&&typeof peGeoInfo.geobytesregion!="undefined")?peGeoInfo.geobytesregion:"",city:(typeof peGeoInfo!="undefined"&&typeof peGeoInfo.geobytescity!="undefined")?peGeoInfo.geobytescity:""}}}}
catch(e){console.log(e);}