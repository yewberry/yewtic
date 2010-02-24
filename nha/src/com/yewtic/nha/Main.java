package com.yewtic.nha;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONObject;

import org.apache.log4j.Logger;

public class Main extends HttpServlet {
	private static Logger log = Logger.getLogger(Main.class);

	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
	throws ServletException, IOException {
		doGet(req, resp);
		return;
	}
	
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		//resp.setContentType("text/xml");
		resp.setCharacterEncoding("utf-8");
		resp.setContentType("text/html");
		
		//String app = req.getParameter("app");
		String rtn = null;
		try {
			//JSONObject json = app.doRequest(req, resp);
			JSONObject json = JSONObject.fromObject("{abc:1}");
			rtn = json.toString();
			
		} catch(Exception e){
			log.error("", e);
			//rtn = Common.errToJson(e).toString();
			rtn = "";
		}

		PrintWriter out = resp.getWriter();
		log.debug(rtn);
		out.print(rtn);
		out.flush();
		out.close();

	}
}
