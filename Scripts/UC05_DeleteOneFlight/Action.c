Action()
{

/*Correlation comment - Do not change!  Original value='134644.527339004zQcfHHHpiHftVfftpzzHcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
	lr_start_transaction("home Page");
		
	web_reg_find("Fail=NotFound",
		"Text=sign up now",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("home Page", LR_AUTO);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("click login");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=52", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		LAST);

	lr_end_transaction("click login",LR_AUTO);
	
	lr_think_time(21);

	lr_start_transaction("click itinerary");
	
	web_reg_find("Fail=NotFound",
		"Text=scheduled flights.",
		LAST);

/*Correlation comment - Do not change!  Original value='210297424-100296-JB' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click itinerary",LR_AUTO);

	lr_think_time(29);

	lr_start_transaction("delete flight");
	
	web_reg_find("Fail=Found",
		"Text={flightID}",
		LAST);

	web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/itinerary.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
		"Snapshot=t8.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID}", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=removeFlights.x", "Value=57", ENDITEM,
		"Name=removeFlights.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("delete flight",LR_AUTO);

	lr_think_time(20);


	lr_start_transaction("sign off");
	
	web_reg_find("Fail=NotFound",
		"Text=Welcome to the Web Tours site.",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign off",LR_AUTO);

	return 0;
}