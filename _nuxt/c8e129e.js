(window.webpackJsonp=window.webpackJsonp||[]).push([[10],{307:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"ja":{"explanation":"説明","dependent_library":"依存ライブラリ","header_file":"ヘッダファイル","source_file":"ソースファイル","reference":"リファレンス","function":"関数","calc_amount":"計算量","constant_multiple":"定数倍","very_light":"とても軽い","light":"軽い","very_heavy":"とても重い","normal":"普通","little_heavy":"少し重い"}}'),delete t.options._Ctor}},308:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"en":{"explanation":"Explanation","dependent_library":"Dependent Library","header_file":"Header File","source_file":"Source File","reference":"Reference","function":"Function","calc_amount":"Calculated Amount","constant_multiple":"Constant Multiple","very_light":"Very Light","light":"Light","very_heavy":"Very Heavy","normal":"Normal","little_heavy":"Little Heavy"}}'),delete t.options._Ctor}},309:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"ja":{"data_strcture":"データ構造","graph":"グラフ","math":"数学","geometry":"幾何","extension_graph":"拡張グラフ","extension_algorithm":"拡張アルゴリズム","custom":"カスタム","binary_indexed_tree":"Binary-Indexed-Tree","union_find":"素集合データ構造(Union-Find)","graph_base":"グラフのベース","dijkstra":"単一始点最短経路(ダイクストラ)","euler_tour":"オイラーツアー","mod_int":"ModInt","geometry_vertex":"点(テンプレート)","enumerative_euler_tour":"数え上げオイラーツアー","algorithm":"アルゴリズム","cumulative_sum":"累積和","combination":"組み合わせ","rerooting":"全方位木DP","segment_tree":"セグメント木","matrix":"行列","affine":"アフィン変換"}}'),delete t.options._Ctor}},310:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"en":{"data_strcture":"Data Strcture","graph":"Graph","math":"Math","geometry":"Geometry","extension_graph":"Extension Graph","extension_algorithm":"Extension Algorithm","custom":"Custom","binary_indexed_tree":"Binary-Indexed-Tree","union_find":"Disjoint-set(Union-Find)","graph_base":"Graph Base","dijkstra":"Single Source Shortest Path(Dijkstra)","euler_tour":"EulerTour","mod_int":"ModInt","geometry_vertex":"Vertex(template)","enumerative_euler_tour":"CountUp EulerTour","algorithm":"Algorithm","cumulative_sum":"Cumulative Sum","combination":"Combination","rerooting":"ReRooting","segment_tree":"Segment Tree","matrix":"Matrix","affine":"Affine Transformation"}}'),delete t.options._Ctor}},311:function(t,e,o){var content=o(315);content.__esModule&&(content=content.default),"string"==typeof content&&(content=[[t.i,content,""]]),content.locals&&(t.exports=content.locals);(0,o(17).default)("1a34e9b2",content,!0,{sourceMap:!1})},312:function(t,e,o){var content=o(313);content.__esModule&&(content=content.default),"string"==typeof content&&(content=[[t.i,content,""]]),content.locals&&(t.exports=content.locals);(0,o(17).default)("2e9bbcb6",content,!0,{sourceMap:!1})},313:function(t,e,o){var r=o(16)(!1);r.push([t.i,'code[class*=language-],pre[class*=language-]{color:#ccc;background:none;font-family:Consolas,Monaco,"Andale Mono","Ubuntu Mono",monospace;font-size:1em;text-align:left;white-space:pre;word-spacing:normal;word-break:normal;word-wrap:normal;line-height:1.5;-moz-tab-size:4;-o-tab-size:4;tab-size:4;-webkit-hyphens:none;-ms-hyphens:none;hyphens:none}pre[class*=language-]{padding:1em;margin:.5em 0;overflow:auto}:not(pre)>code[class*=language-],pre[class*=language-]{background:#2d2d2d}:not(pre)>code[class*=language-]{padding:.1em;border-radius:.3em;white-space:normal}.token.block-comment,.token.cdata,.token.comment,.token.doctype,.token.prolog{color:#999}.token.punctuation{color:#ccc}.token.attr-name,.token.deleted,.token.namespace,.token.tag{color:#e2777a}.token.function-name{color:#6196cc}.token.boolean,.token.function,.token.number{color:#f08d49}.token.class-name,.token.constant,.token.property,.token.symbol{color:#f8c555}.token.atrule,.token.builtin,.token.important,.token.keyword,.token.selector{color:#cc99cd}.token.attr-value,.token.char,.token.regex,.token.string,.token.variable{color:#7ec699}.token.entity,.token.operator,.token.url{color:#67cdcc}.token.bold,.token.important{font-weight:700}.token.italic{font-style:italic}.token.entity{cursor:help}.token.inserted{color:green}',""]),t.exports=r},314:function(t,e,o){"use strict";o(311)},315:function(t,e,o){var r=o(16)(!1);r.push([t.i,".source-copy .v-icon{position:absolute;right:0;z-index:4}.source-github .v-icon{position:absolute}",""]),t.exports=r},316:function(t,e,o){"use strict";o(200);var r=o(324),n=o.n(r),l=(o(312),o(325),o(326),o(327)),d=o.n(l);var c={props:["src","link"],components:{Prism:n.a},data:function(){return{copied:!1,source_code:""}},methods:{copySource:function(){var element;(element=this.$el.querySelector("pre")).setAttribute("contenteditable","true"),element.focus(),document.execCommand("selectAll",!1),document.execCommand("copy"),element.setAttribute("contenteditable","false")},openSource:function(){open(this.link,"_blank")}},mounted:function(){var t=this;d.a.get(this.src).then((function(e){return t.source_code=e.data}))}},h=(o(314),o(73)),_=o(99),v=o.n(_),f=o(405),m=o(148),component=Object(h.a)(c,(function(){var t=this,e=t.$createElement,o=t._self._c||e;return o("v-card",{staticClass:"source-card",attrs:{outlined:"",color:"#2d2d2d"}},[o("div",{staticClass:"source-copy"},[o("v-icon",{attrs:{title:"Copy","aria-label":"Copy",size:"25",color:"white"},on:{click:t.copySource}},[t._v("\n      mdi-content-copy\n    ")])],1),t._v(" "),o("div",{staticClass:"source-github"},[o("v-icon",{attrs:{title:"View on GitHub","aria-label":"View on GitHub",color:"white",size:"25"},on:{click:t.openSource}},[t._v(" \n      mdi-github \n    ")])],1),t._v(" "),o("prism",{attrs:{language:"cpp",code:t.source_code}})],1)}),[],!1,null,null,null);e.a=component.exports;v()(component,{VCard:f.a,VIcon:m.a})},317:function(t,e,o){"use strict";var r=o(307),n=o.n(r);e.default=n.a},318:function(t,e,o){"use strict";var r=o(308),n=o.n(r);e.default=n.a},319:function(t,e,o){"use strict";var r=o(309),n=o.n(r);e.default=n.a},320:function(t,e,o){"use strict";var r=o(310),n=o.n(r);e.default=n.a},321:function(t,e,o){var content=o(322);content.__esModule&&(content=content.default),"string"==typeof content&&(content=[[t.i,content,""]]),content.locals&&(t.exports=content.locals);(0,o(17).default)("7c06aa28",content,!0,{sourceMap:!1})},322:function(t,e,o){var r=o(16)(!1);r.push([t.i,".theme--light.v-data-table{background-color:#fff;color:rgba(0,0,0,.87)}.theme--light.v-data-table .v-data-table__divider{border-right:thin solid rgba(0,0,0,.12)}.theme--light.v-data-table.v-data-table--fixed-header thead th{background:#fff;box-shadow:inset 0 -1px 0 rgba(0,0,0,.12)}.theme--light.v-data-table>.v-data-table__wrapper>table>thead>tr>th{color:rgba(0,0,0,.6)}.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>td:last-child,.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>td:not(.v-data-table__mobile-row),.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>th:last-child,.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>th:not(.v-data-table__mobile-row),.theme--light.v-data-table>.v-data-table__wrapper>table>thead>tr:last-child>th{border-bottom:thin solid rgba(0,0,0,.12)}.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr.active{background:#f5f5f5}.theme--light.v-data-table>.v-data-table__wrapper>table>tbody>tr:hover:not(.v-data-table__expanded__content):not(.v-data-table__empty-wrapper){background:#eee}.theme--dark.v-data-table{background-color:#1e1e1e;color:#fff}.theme--dark.v-data-table .v-data-table__divider{border-right:thin solid hsla(0,0%,100%,.12)}.theme--dark.v-data-table.v-data-table--fixed-header thead th{background:#1e1e1e;box-shadow:inset 0 -1px 0 hsla(0,0%,100%,.12)}.theme--dark.v-data-table>.v-data-table__wrapper>table>thead>tr>th{color:hsla(0,0%,100%,.7)}.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>td:last-child,.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>td:not(.v-data-table__mobile-row),.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>th:last-child,.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr:not(:last-child)>th:not(.v-data-table__mobile-row),.theme--dark.v-data-table>.v-data-table__wrapper>table>thead>tr:last-child>th{border-bottom:thin solid hsla(0,0%,100%,.12)}.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr.active{background:#505050}.theme--dark.v-data-table>.v-data-table__wrapper>table>tbody>tr:hover:not(.v-data-table__expanded__content):not(.v-data-table__empty-wrapper){background:#616161}.v-data-table{line-height:1.5;max-width:100%}.v-data-table>.v-data-table__wrapper>table{width:100%;border-spacing:0}.v-data-table>.v-data-table__wrapper>table>tbody>tr>td,.v-data-table>.v-data-table__wrapper>table>tbody>tr>th,.v-data-table>.v-data-table__wrapper>table>tfoot>tr>td,.v-data-table>.v-data-table__wrapper>table>tfoot>tr>th,.v-data-table>.v-data-table__wrapper>table>thead>tr>td,.v-data-table>.v-data-table__wrapper>table>thead>tr>th{padding:0 16px;transition:height .2s cubic-bezier(.4,0,.6,1)}.v-data-table>.v-data-table__wrapper>table>tbody>tr>th,.v-data-table>.v-data-table__wrapper>table>tfoot>tr>th,.v-data-table>.v-data-table__wrapper>table>thead>tr>th{-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;font-size:.75rem;height:48px}.v-application--is-ltr .v-data-table>.v-data-table__wrapper>table>tbody>tr>th,.v-application--is-ltr .v-data-table>.v-data-table__wrapper>table>tfoot>tr>th,.v-application--is-ltr .v-data-table>.v-data-table__wrapper>table>thead>tr>th{text-align:left}.v-application--is-rtl .v-data-table>.v-data-table__wrapper>table>tbody>tr>th,.v-application--is-rtl .v-data-table>.v-data-table__wrapper>table>tfoot>tr>th,.v-application--is-rtl .v-data-table>.v-data-table__wrapper>table>thead>tr>th{text-align:right}.v-data-table>.v-data-table__wrapper>table>tbody>tr>td,.v-data-table>.v-data-table__wrapper>table>tfoot>tr>td,.v-data-table>.v-data-table__wrapper>table>thead>tr>td{font-size:.875rem;height:48px}.v-data-table__wrapper{overflow-x:auto;overflow-y:hidden}.v-data-table__progress{height:auto!important}.v-data-table__progress th{height:auto!important;border:none!important;padding:0;position:relative}.v-data-table--dense>.v-data-table__wrapper>table>tbody>tr>td,.v-data-table--dense>.v-data-table__wrapper>table>tbody>tr>th,.v-data-table--dense>.v-data-table__wrapper>table>tfoot>tr>td,.v-data-table--dense>.v-data-table__wrapper>table>tfoot>tr>th,.v-data-table--dense>.v-data-table__wrapper>table>thead>tr>td,.v-data-table--dense>.v-data-table__wrapper>table>thead>tr>th{height:32px}.v-data-table--has-top>.v-data-table__wrapper>table>tbody>tr:first-child:hover>td:first-child{border-top-left-radius:0}.v-data-table--has-top>.v-data-table__wrapper>table>tbody>tr:first-child:hover>td:last-child{border-top-right-radius:0}.v-data-table--has-bottom>.v-data-table__wrapper>table>tbody>tr:last-child:hover>td:first-child{border-bottom-left-radius:0}.v-data-table--has-bottom>.v-data-table__wrapper>table>tbody>tr:last-child:hover>td:last-child{border-bottom-right-radius:0}.v-data-table--fixed-header>.v-data-table__wrapper,.v-data-table--fixed-height .v-data-table__wrapper{overflow-y:auto}.v-data-table--fixed-header>.v-data-table__wrapper>table>thead>tr>th{border-bottom:0!important;position:sticky;top:0;z-index:2}.v-data-table--fixed-header>.v-data-table__wrapper>table>thead>tr:nth-child(2)>th{top:48px}.v-application--is-ltr .v-data-table--fixed-header .v-data-footer{margin-right:17px}.v-application--is-rtl .v-data-table--fixed-header .v-data-footer{margin-left:17px}.v-data-table--fixed-header.v-data-table--dense>.v-data-table__wrapper>table>thead>tr:nth-child(2)>th{top:32px}",""]),t.exports=r},323:function(t,e,o){"use strict";var r={props:["headerRaw","headerGitHubLink","sourceRaw","sourceGitHubLink","dependentList","japanese","english"],components:{SourceView:o(316).a},data:function(){return{dependent_libraries:"",reference_about:"",func_reference:""}},created:function(){this.$i18n.mergeLocaleMessage("ja",this.japanese),this.$i18n.mergeLocaleMessage("en",this.english),this.dependent_libraries=this.dependentList.dependent_libraries,this.reference_about=this.dependentList.reference_about,this.func_reference=this.dependentList.func_reference,window.MathJax&&(window.MathJax.Hub.Config({tex2jax:{inlineMath:[["$","$"]],displayMath:[["$$","$$"]],processEscapes:!0,processEnvironments:!0},displayAlign:"center","HTML-CSS":{fonts:["TeX"]}}),window.MathJax.Hub.Rerender(["Typeset",window.MathJax.Hub]))},head:function(){return{title:this.$t("library_name")}}},n=o(73),l=o(317),d=o(318),c=o(319),h=o(320),_=o(99),v=o.n(_),f=o(147),m=(o(12),o(8),o(7),o(5),o(4),o(9),o(2)),x=(o(19),o(321),o(1)),w=o(27),y=o(11);function k(object,t){var e=Object.keys(object);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(object);t&&(o=o.filter((function(t){return Object.getOwnPropertyDescriptor(object,t).enumerable}))),e.push.apply(e,o)}return e}var $=Object(y.a)(w.a).extend({name:"v-simple-table",props:{dense:Boolean,fixedHeader:Boolean,height:[Number,String]},computed:{classes:function(){return function(t){for(var i=1;i<arguments.length;i++){var source=null!=arguments[i]?arguments[i]:{};i%2?k(Object(source),!0).forEach((function(e){Object(m.a)(t,e,source[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(t,Object.getOwnPropertyDescriptors(source)):k(Object(source)).forEach((function(e){Object.defineProperty(t,e,Object.getOwnPropertyDescriptor(source,e))}))}return t}({"v-data-table--dense":this.dense,"v-data-table--fixed-height":!!this.height&&!this.fixedHeader,"v-data-table--fixed-header":this.fixedHeader,"v-data-table--has-top":!!this.$slots.top,"v-data-table--has-bottom":!!this.$slots.bottom},this.themeClasses)}},methods:{genWrapper:function(){return this.$slots.wrapper||this.$createElement("div",{staticClass:"v-data-table__wrapper",style:{height:Object(x.f)(this.height)}},[this.$createElement("table",this.$slots.default)])}},render:function(t){return t("div",{staticClass:"v-data-table",class:this.classes},[this.$slots.top,this.genWrapper(),this.$slots.bottom])}}),component=Object(n.a)(r,(function(){var t=this,e=t.$createElement,o=t._self._c||e;return o("v-responsive",{staticClass:"mx-auto",attrs:{"max-width":"1024"}},[o("section",{staticClass:"mb-12"},[o("h1",{staticClass:"display-1 font-weight-bold mb-2"},[t._v(" "+t._s(t.$t("library_name"))+" ")]),t._v(" "),o("p",{staticClass:"font-weight-right title"},[t._v(" \n      "+t._s(t.$t("overview"))+"\n    ")])]),t._v(" "),o("section",{staticClass:"mb-12"},[o("h2",[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),o("p",[t._v(" "+t._s(t.$t("explanation_content")))])]),t._v(" "),t.dependent_libraries?o("section",{staticClass:"mb-12"},[o("h2",[t._v(" "+t._s(t.$t("dependent_library"))+" ")]),t._v(" "),t._l(t.dependent_libraries,(function(e){return o("ul",{key:e},[o("li",[o("nuxt-link",{attrs:{to:t.localePath(e.link)}},[t._v(" "+t._s(t.$t(e.name))+" ")])],1)])}))],2):t._e(),t._v(" "),t.func_reference?o("section",{staticClass:"mb-12"},[o("h2",[t._v(" "+t._s(t.$t("reference"))+" ")]),t._v(" "),t.reference_about?o("p",[t._v(" "+t._s(t.$t("reference_about"))+" ")]):t._e(),t._v(" "),o("v-simple-table",{scopedSlots:t._u([{key:"default",fn:function(){return[o("thead",[o("th",{attrs:{width:"350sp"}},[t._v(" "+t._s(t.$t("function"))+" ")]),t._v(" "),o("th",{attrs:{width:"350sp"}},[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),o("th",[t._v(" "+t._s(t.$t("calc_amount"))+" ")])]),t._v(" "),o("tbody",t._l(t.func_reference,(function(e){return o("tr",{key:e.function},[o("td",[t._v(" "+t._s(e.function)+" ")]),t._v(" "),o("td",[t._v(" "+t._s(t.$t(e.explanation))+" ")]),t._v(" "),o("td",[t._v(" "+t._s(e.amount)+" ")])])})),0)]},proxy:!0}],null,!1,946098611)})],1):t._e(),t._v(" "),o("section",{staticClass:"mb-12"},[o("h2",[t._v(" "+t._s(t.$t("header_file"))+" ")]),t._v(" "),o("SourceView",{attrs:{src:t.headerRaw,link:t.headerGitHubLink}})],1),t._v(" "),t.sourceRaw?o("section",{staticClass:"mb-12"},[o("h2",[t._v(" "+t._s(t.$t("source_file"))+" ")]),t._v(" "),o("SourceView",{attrs:{src:t.sourceRaw,link:t.sourceGitHubLink}})],1):t._e()])}),[],!1,null,null,null);"function"==typeof l.default&&Object(l.default)(component),"function"==typeof d.default&&Object(d.default)(component),"function"==typeof c.default&&Object(c.default)(component),"function"==typeof h.default&&Object(h.default)(component);e.a=component.exports;v()(component,{VResponsive:f.a,VSimpleTable:$})},377:function(t){t.exports=JSON.parse('{"ja":{"library_name":"点（一応幾何問題のテンプレート）","overview":"幾何問題を扱うときの点．つまり幾何問題を扱うときに必要なライブラリ．幾何に関するライブラリのほとんどがこのライブラリに依存すると思う．","explanation_content":"点ですね．頂点でもok．まあ，厳密に言うならベクトルかな","reference_about":"下に書いてないやつはコードみて察してください．各operatorも，ただただ加算とかしてるだけ","dot_explanation":"$p$との内積を求める","cross_explanation":"$p$との外積を求める","before_norm_explanation":"ノルム計算の前を求める．すなわち$x^2 + y^2$","norm_explanation":"ノルムを求める，すなわち$\\\\sqrt{x^2 + y^2}$","rotate_orthant_explanation":"象限回転を行なう．すなわち象限の移動","rotate_theta_explanation":"半時計回りに$\\\\theta$回転を行なう(象限にそって回転させる)","orthant_explanation":"象限を求める","operator_less_than_explanation":"象限などにそって，半時計回りに比較を行なう（ソートとかに使える）"}}')},378:function(t){t.exports=JSON.parse('{"en":{"library_name":"Points","overview":"Points to consider when dealing with geometric problems. That is, the library needed to work with geometry problems. I think most of the libraries on geometry depend on this library. (Geometry Problem Template, Just in case...?)","explanation_content":"That\'s a point. Vertex is OK...well, strictly speaking, a vector.","reference_about":"If it\'s not at the bottom, please look at the code. Each operator is just adding more and more.","dot_explanation":"Calculate the inner product of $p$.","cross_explanation":"Calculate the outer product of $p$.","before_norm_explanation":"Calculate the front of the norm calculation. I.e. $x^2 + y^2$.","norm_explanation":"Calculate norm. I.e. $x^2 + y^2$.","rotate_orthant_explanation":"Perform orthant rotation. I.e. the orthant move","rotate_theta_explanation":"Perform $\\\\theta$ rotation on a counterclockwise rotation (rotation along a orthant)","orthant_explanation":"Calculate orthant","operator_less_than_explanation":"Compare with Orthant and others. (can be used for sorting, etc.)"}}')},398:function(t,e,o){"use strict";o.r(e);var r=o(323),n=function(){return{reference_about:"reference_about",func_reference:[{function:"dot$(p)$",explanation:"dot_explanation",amount:"$O(1)$"},{function:"cross$(p)$",explanation:"cross_explanation",amount:"$O(1)$"},{function:"before_norm$(p)$",explanation:"before_norm_explanation",amount:"$O(1)$"},{function:"norm$(p)$",explanation:"norm_explanation",amount:"$O(1)$"},{function:"rotate_orthant$()$",explanation:"rotate_orthant_explanation",amount:"$O(1)$"},{function:"rotate_theta$(\\theta)$",explanation:"rotate_theta_explanation",amount:"$O(1)$"},{function:"orthant$()$",explanation:"orthant_explanation",amount:"$O(1)$"},{function:"operator$<$",explanation:"operator_less_than_explanation",amount:"$O(1)$"}]}},l=o(377),d=o(378),c={components:{LibraryPage:r.a},data:function(){return{Japanese:l,English:d,dependent_list:n()}}},h=o(73),component=Object(h.a)(c,(function(){var t=this,e=t.$createElement;return(t._self._c||e)("LibraryPage",{attrs:{headerRaw:"https://raw.githubusercontent.com/jellyfish26/competitive-library/master/geometry/Vertex.hpp",headerGitHubLink:"https://github.com/jellyfish26/competitive-library/blob/master/geometry/Vertex.hpp",dependentList:t.dependent_list,japanese:t.Japanese.ja,english:t.English.en}})}),[],!1,null,null,null);e.default=component.exports}}]);