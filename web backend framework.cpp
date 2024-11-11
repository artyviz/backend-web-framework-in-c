
//concept

/*
dto(struct s_credentials, "cred")
struct s_credentials 
{
	char username[20];
	char password[12];
};


$post(login, "/users/login")
bool login(Request* req, response* res)
{
	char* user, * pass;
	user = req->cred->username;
	pass = req->cred->password;

	if (!strcmp(user, "random")
		&& (!strcmp(pass, "name")))
	{
		req.session.loggedin = true;
		return json("{'loggedin': true}");
	}
	else {
		res.errorcode = 300;
		retrun httperror(res, "unauthorized");
	}
}*/
