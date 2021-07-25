import React, { Component } from 'react';
// import {} from './ThemeSwitcherStyles.js';

export default class ThemeSwitcher extends Component {
	state = {
		theme: null
	}
	
	chooseTheme = (evt) => {
		evt.preventDefault();
		this.setState({ theme: null });
	};

	render() {
		return (
			<>
				<h1>ThemeSwitcher Component</h1>
			</>
		);
	}
}

/* As I'm reading through this tutorial I came across this:
 <button type="button" className={`btn btn-${themeClass} btn-lg`}>{ theme || 'Choose' } Theme</button>
 omg, and then I was like wtf are the {}{}{}}. So here's the rundown:
 The encapsulating one is a JSX feature, it's how it knows when you are putting JS expressions
 inside of your "JSX syntactic sugar", and in this case, the JS expression is a "Template
 Literal" which uses another set of {} (note, this is a JS feature). Anyways yeah. TEMPLATE
 LITERALS, I remembered that JSX uses {} to insert JS expressions, but I forgot about TEMPLATE
 \LITERALS. I remember those giving me crap before too. Goddamn there's a lot of bs in JS.*/