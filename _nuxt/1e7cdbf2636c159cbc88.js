(window.webpackJsonp=window.webpackJsonp||[]).push([[6],{294:function(t,e,n){var content=n(298);"string"==typeof content&&(content=[[t.i,content,""]]),content.locals&&(t.exports=content.locals);(0,n(14).default)("4f4aef1d",content,!0,{sourceMap:!1})},295:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"ja":{"explanation":"説明","dependent_library":"依存ライブラリ","source_code":"ソースコード","reference":"リファレンス","function":"関数","calc_amount":"計算量","constant_multiple":"定数倍","very_light":"とても軽い","light":"軽い"}}'),delete t.options._Ctor}},296:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"en":{"explanation":"Explanation","dependent_library":"Dependent Library","source_code":"Source Code","reference":"Reference","function":"Function","calc_amount":"Calculated Amount","constant_multiple":"Constant Multiple","very_light":"Very Light","light":"Light"}}'),delete t.options._Ctor}},297:function(t,e,n){"use strict";var o=n(294);n.n(o).a},298:function(t,e,n){(e=n(13)(!1)).push([t.i,".source-copy .v-icon{position:absolute;right:0;z-index:4}.source-github .v-icon{position:absolute}",""]),t.exports=e},299:function(t,e,n){"use strict";n(184),n(120),n(304),n(305);var o=n(306),r=n.n(o);var c={props:["src","link"],components:{Prism:function(){return n.e(15).then(n.t.bind(null,361,7))}},data:function(){return{copied:!1,source_code:""}},methods:{copySource:function(){var element;(element=this.$el.querySelector("pre")).setAttribute("contenteditable","true"),element.focus(),document.execCommand("selectAll",!1),document.execCommand("copy"),element.setAttribute("contenteditable","false")},openSource:function(){open(this.link,"_blank")}},mounted:function(){var t=this;r.a.get(this.src).then((function(e){return t.source_code=e.data}))}},l=(n(297),n(67)),_=n(94),h=n.n(_),f=n(357),d=n(137),component=Object(l.a)(c,(function(){var t=this.$createElement,e=this._self._c||t;return e("v-card",{staticClass:"source-card",attrs:{outlined:"",color:"#2d2d2d"}},[e("div",{staticClass:"source-copy"},[e("v-icon",{attrs:{title:"Copy","aria-label":"Copy",size:"25",color:"white"},on:{click:this.copySource}},[this._v("\n      mdi-content-copy\n    ")])],1),this._v(" "),e("div",{staticClass:"source-github"},[e("v-icon",{attrs:{title:"View on GitHub","aria-label":"View on GitHub",color:"white",size:"25"},on:{click:this.openSource}},[this._v(" \n      mdi-github \n    ")])],1),this._v(" "),e("prism",{attrs:{language:"cpp",code:this.source_code}})],1)}),[],!1,null,null,null);e.a=component.exports;h()(component,{VCard:f.a,VIcon:d.a})},301:function(t,e,n){"use strict";var o=n(295),r=n.n(o);e.default=r.a},302:function(t,e,n){"use strict";var o=n(296),r=n.n(o);e.default=r.a},303:function(t,e,n){"use strict";var o=n(299),r={props:["formula"],watch:{formula:function(){this.renderMathJax()}},mounted:function(){this.renderMathJax()},methods:{renderMathJax:function(){this.$refs.mathJaxElement.innerHTML=this.formula,window.MathJax&&(window.MathJax.Hub.Config({tex2jax:{inlineMath:[["$","$"]],displayMath:[["$$","$$"]],processEscapes:!0,processEnvironments:!0},displayAlign:"center","HTML-CSS":{fonts:["TeX"]}}),window.MathJax.Hub.Queue(["Typeset",window.MathJax.Hub,this.$refs.mathJaxElement]))}}},c=n(67),l=Object(c.a)(r,(function(){var t=this.$createElement;return(this._self._c||t)("span",{ref:"mathJaxElement"},[this._v(this._s(this.formula))])}),[],!1,null,null,null).exports,_={props:["sourceRaw","sourceGitHubLink","dependentList","japanese","english"],components:{SourceView:o.a,MathJax2:l},data:function(){return{dependent_libraries:"",reference_about:"",func_reference:""}},mounted:function(){this.$i18n.mergeLocaleMessage("ja",this.japanese),this.$i18n.mergeLocaleMessage("en",this.english),this.dependent_libraries=this.dependentList.dependent_libraries,this.reference_about=this.dependentList.reference_about,this.func_reference=this.dependentList.func_reference},head:function(){return{title:this.$t("library_name")}}},h=n(301),f=n(302),d=n(94),m=n.n(d),x=n(136),$=n(360),v=Object(c.a)(_,(function(){var t=this,e=t.$createElement,n=t._self._c||e;return n("v-responsive",{staticClass:"mx-auto",attrs:{"max-width":"1024"}},[n("section",{staticClass:"mb-12"},[n("h1",{staticClass:"display-1 font-weight-bold mb-2"},[t._v(" "+t._s(t.$t("library_name"))+" ")]),t._v(" "),n("p",{staticClass:"font-weight-right title"},[n("MathJax2",{attrs:{formula:t.$t("overview")}})],1)]),t._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),n("p",[n("MathJax2",{attrs:{formula:t.$t("explanation_content")}})],1)]),t._v(" "),t.dependent_libraries?n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("dependent_library"))+" ")]),t._v(" "),t._l(t.dependent_libraries,(function(e){return n("ul",[n("li",[n("nuxt-link",{attrs:{to:t.localePath(e.link)}},[t._v(" "+t._s(t.$t(e.name))+" ")])],1)])}))],2):t._e(),t._v(" "),t.func_reference?n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("reference"))+" ")]),t._v(" "),t.reference_about?n("p",[n("MathJax2",{attrs:{formula:t.$t(t.reference_about)}})],1):t._e(),t._v(" "),n("v-simple-table",{scopedSlots:t._u([{key:"default",fn:function(){return[n("thead",[n("th",{attrs:{width:"250sp"}},[t._v(" "+t._s(t.$t("function"))+" ")]),t._v(" "),n("th",{attrs:{width:"300sp"}},[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),n("th",[t._v(" "+t._s(t.$t("calc_amount"))+" ")]),t._v(" "),n("th",[t._v(" "+t._s(t.$t("constant_multiple"))+" ")])]),t._v(" "),n("tbody",t._l(t.func_reference,(function(e){return n("tr",{key:e.function},[n("td",[n("MathJax2",{attrs:{formula:e.function}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:t.$t(e.explanation)}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:e.amount}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:t.$t(e.constant_times)}})],1)])})),0)]},proxy:!0}],null,!1,3476379124)})],1):t._e(),t._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("source_code"))+" ")]),t._v(" "),n("SourceView",{attrs:{src:t.sourceRaw,link:t.sourceGitHubLink}})],1)])}),[],!1,null,null,null);"function"==typeof h.default&&Object(h.default)(v),"function"==typeof f.default&&Object(f.default)(v);e.a=v.exports;m()(v,{VResponsive:x.a,VSimpleTable:$.a})},347:function(t){t.exports=JSON.parse('{"ja":{"library_name":"点（一応幾何問題のテンプレート）","overview":"幾何問題を扱うときの点．つまり幾何問題を扱うときに必要なライブラリ．幾何に関するライブラリのほとんどがこのライブラリに依存すると思う．","explanation_content":"点ですね．頂点でもok．まあ，厳密に言うならベクトルかな","reference_about":"下に書いてないやつはコードみて察してください．各operatorも，ただただ加算とかしてるだけ","dot_explanation":"$p$との内積を求める","cross_explanation":"$p$との外積を求める","before_norm_explanation":"ノルム計算の前を求める．すなわち$x^2 + y^2$","norm_explanation":"ノルムを求める，すなわち$\\\\sqrt{x^2 + y^2}$","rotate_orthant_explanation":"象限回転を行なう．すなわち象限の移動","rotate_theta_explanation":"半時計回りに$\\\\theta$回転を行なう(象限にそって回転させる)","orthant_explanation":"象限を求める","operator_less_than_explanation":"象限などにそって，半時計回りに比較を行なう（ソートとかに使える）"}}')},348:function(t){t.exports=JSON.parse('{"en":{"library_name":"Points","overview":"Points to consider when dealing with geometric problems. That is, the library needed to work with geometry problems. I think most of the libraries on geometry depend on this library. (Geometry Problem Template, Just in case...?)","explanation_content":"That\'s a point. Vertex is OK...well, strictly speaking, a vector.","reference_about":"If it\'s not at the bottom, please look at the code. Each operator is just adding more and more.","dot_explanation":"Calculate the inner product of $p$.","cross_explanation":"Calculate the outer product of $p$.","before_norm_explanation":"Calculate the front of the norm calculation. I.e. $x^2 + y^2$.","norm_explanation":"Calculate norm. I.e. $x^2 + y^2$.","rotate_orthant_explanation":"Perform orthant rotation. I.e. the orthant move","rotate_theta_explanation":"Perform $\\\\theta$ rotation on a counterclockwise rotation (rotation along a orthant)","orthant_explanation":"Calculate orthant","operator_less_than_explanation":"Compare with Orthant and others. (can be used for sorting, etc.)"}}')},364:function(t,e,n){"use strict";n.r(e);var o=n(303),r=function(){return{reference_about:"reference_about",func_reference:[{function:"dot$(p)$",explanation:"dot_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"cross$(p)$",explanation:"cross_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"before_norm$(p)$",explanation:"before_norm_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"norm$(p)$",explanation:"norm_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"rotate_orthant$()$",explanation:"rotate_orthant_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"rotate_theta$(\\theta)$",explanation:"rotate_theta_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"orthant$()$",explanation:"orthant_explanation",amount:"$O(1)$",constant_times:"very_light"},{function:"operator$<$",explanation:"operator_less_than_explanation",amount:"$O(1)$",constant_times:"very_light"}]}},c=n(347),l=n(348),_={components:{LibraryPage:o.a},data:function(){return{Japanese:c,English:l,dependent_list:r()}}},h=n(67),component=Object(h.a)(_,(function(){var t=this.$createElement;return(this._self._c||t)("LibraryPage",{attrs:{sourceRaw:"https://raw.githubusercontent.com/jellyfish26/competitive-library/master/geometry/Point.cpp",sourceGitHubLink:"https://github.com/jellyfish26/competitive-library/blob/master/geometry/Point.cpp",dependentList:this.dependent_list,japanese:this.Japanese.ja,english:this.English.en}})}),[],!1,null,null,null);e.default=component.exports}}]);