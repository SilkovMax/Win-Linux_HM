Action()
{
	
	tName = "03.OpenPage_ticket_FindFlight";
	lr_start_transaction(tName);


	status=web_url("Search Flights Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status); lr_think_time(4);
	
	tName = "04.Create_ticket_FindFlight";
	lr_start_transaction(tName);
	
	 web_reg_save_param_ex(
        "ParamName=OFlight", 
        "LB=\"outboundFlight\" value=\"",               
        "RB=\"",
		"Ordinal=1",                                  
    LAST); 
	
	

	status=web_submit_data("reservations.pl", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value={Discont}", ENDITEM, 
		"Name=depart", "Value={CityOUT}", ENDITEM, 
		"Name=departDate", "Value={Date1}", ENDITEM, 
		"Name=arrive", "Value={CItyIN}", ENDITEM, 
		"Name=returnDate", "Value={Date2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=seatType", "Value={TypePref}", ENDITEM, 
		"Name=findFlights.x", "Value=67", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	
	end_transaction(tName, status); lr_think_time(4);
	
	
	tName = "05.Create_ticket_ChooseCost";
	lr_start_transaction(tName);

	status=web_submit_data("reservations.pl_2", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value={Discont}", ENDITEM, 
		"Name=seatType", "Value={TypePref}", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=39", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);
	
	
	end_transaction(tName, status); lr_think_time(4);

	
	tName = "06.Create_ticket_PaymentDetail";
	lr_start_transaction(tName);
	

	status=web_submit_data("reservations.pl_3", 
		"Action={Host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={adress1}", ENDITEM, 
		"Name=address2", "Value={adress2}", ENDITEM, 
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
		"Name=creditCard", "Value=4242515156566060", ENDITEM, 
		"Name=expDate", "Value=12/24", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={TypePref}", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={OFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value={Discont}", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=42", ENDITEM, 
		"Name=buyFlights.y", "Value=0", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	
	end_transaction(tName, status); lr_think_time(4);
	
	

	

	return 0;
}