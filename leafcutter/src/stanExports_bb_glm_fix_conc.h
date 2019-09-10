// Generated by rstantools.  Do not edit by hand.

/*
    leafcutter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    leafcutter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with leafcutter.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1

#include <stan/model/model_header.hpp>

namespace model_bb_glm_fix_conc_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_bb_glm_fix_conc");
    reader.add_event(30, 28, "end", "model_bb_glm_fix_conc");
    return reader;
}

#include <stan_meta_header.hpp>
 class model_bb_glm_fix_conc : public prob_grad {
private:
        int N;
        int P;
        matrix_d x;
        std::vector<int> ys;
        std::vector<int> ns;
        double conc;
        double concShape;
        double concRate;
public:
    model_bb_glm_fix_conc(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_bb_glm_fix_conc(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_bb_glm_fix_conc_namespace::model_bb_glm_fix_conc";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);

            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "P", "int", context__.to_vec());
            P = int(0);
            vals_i__ = context__.vals_i("P");
            pos__ = 0;
            P = vals_i__[pos__++];
            check_greater_or_equal(function__, "P", P, 0);

            current_statement_begin__ = 4;
            validate_non_negative_index("x", "N", N);
            validate_non_negative_index("x", "P", P);
            context__.validate_dims("data initialization", "x", "matrix_d", context__.to_vec(N,P));
            x = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, P);
            vals_r__ = context__.vals_r("x");
            pos__ = 0;
            size_t x_j_2_max__ = P;
            size_t x_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < x_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < x_j_1_max__; ++j_1__) {
                    x(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 5;
            validate_non_negative_index("ys", "N", N);
            context__.validate_dims("data initialization", "ys", "int", context__.to_vec(N));
            ys = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("ys");
            pos__ = 0;
            size_t ys_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < ys_k_0_max__; ++k_0__) {
                ys[k_0__] = vals_i__[pos__++];
            }
            size_t ys_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < ys_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "ys[i_0__]", ys[i_0__], 0);
            }

            current_statement_begin__ = 6;
            validate_non_negative_index("ns", "N", N);
            context__.validate_dims("data initialization", "ns", "int", context__.to_vec(N));
            ns = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("ns");
            pos__ = 0;
            size_t ns_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < ns_k_0_max__; ++k_0__) {
                ns[k_0__] = vals_i__[pos__++];
            }
            size_t ns_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < ns_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "ns[i_0__]", ns[i_0__], 0);
            }

            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "conc", "double", context__.to_vec());
            conc = double(0);
            vals_r__ = context__.vals_r("conc");
            pos__ = 0;
            conc = vals_r__[pos__++];
            check_greater_or_equal(function__, "conc", conc, 0);

            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "concShape", "double", context__.to_vec());
            concShape = double(0);
            vals_r__ = context__.vals_r("concShape");
            pos__ = 0;
            concShape = vals_r__[pos__++];
            check_greater_or_equal(function__, "concShape", concShape, 0);

            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "concRate", "double", context__.to_vec());
            concRate = double(0);
            vals_r__ = context__.vals_r("concRate");
            pos__ = 0;
            concRate = vals_r__[pos__++];
            check_greater_or_equal(function__, "concRate", concRate, 0);


            // initialize transformed data variables
            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 12;
            validate_non_negative_index("beta", "P", P);
            num_params_r__ += P;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_bb_glm_fix_conc() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 12;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "P", P);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(P));
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta(P);
        size_t beta_j_1_max__ = P;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 12;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(P, lp__);
            else
                beta = in__.vector_constrain(P);

            // model body
            {
            current_statement_begin__ = 15;
            validate_non_negative_index("xb", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> xb(N);
            stan::math::initialize(xb, DUMMY_VAR__);
            stan::math::fill(xb, DUMMY_VAR__);

            current_statement_begin__ = 16;
            validate_non_negative_index("a", "N", N);
            std::vector<local_scalar_t__  > a(N, local_scalar_t__(DUMMY_VAR__));
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);

            current_statement_begin__ = 17;
            validate_non_negative_index("b", "N", N);
            std::vector<local_scalar_t__  > b(N, local_scalar_t__(DUMMY_VAR__));
            stan::math::initialize(b, DUMMY_VAR__);
            stan::math::fill(b, DUMMY_VAR__);

            current_statement_begin__ = 18;
            validate_non_negative_index("p", "N", N);
            std::vector<local_scalar_t__  > p(N, local_scalar_t__(DUMMY_VAR__));
            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p, DUMMY_VAR__);


            current_statement_begin__ = 19;
            stan::math::assign(xb, multiply(x, beta));
            current_statement_begin__ = 20;
            for (int n = 1; n <= N; ++n) {

                current_statement_begin__ = 21;
                stan::model::assign(p, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            inv_logit(get_base1(xb, n, "xb", 1)), 
                            "assigning variable p");
                current_statement_begin__ = 22;
                stan::model::assign(a, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (conc * get_base1(p, n, "p", 1)), 
                            "assigning variable a");
                current_statement_begin__ = 23;
                stan::model::assign(b, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (conc * (1.0 - get_base1(p, n, "p", 1))), 
                            "assigning variable b");
            }
            current_statement_begin__ = 26;
            lp_accum__.add(gamma_log<propto__>(conc, concShape, concRate));
            current_statement_begin__ = 27;
            lp_accum__.add(beta_binomial_log<propto__>(ys, ns, a, b));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("beta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(P);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_bb_glm_fix_conc_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta = in__.vector_constrain(P);
        size_t beta_j_1_max__ = P;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            vars__.push_back(beta(j_1__));
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_bb_glm_fix_conc";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = P;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t beta_j_1_max__ = P;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef model_bb_glm_fix_conc_namespace::model_bb_glm_fix_conc stan_model;


#endif
