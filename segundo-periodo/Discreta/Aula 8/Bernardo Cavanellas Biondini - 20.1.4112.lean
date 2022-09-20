variable U : Type.

variable u : U

variables P Q R : U → Prop.

lemma exB 
    (H : ∀ x, P x → ¬ Q x) : 
    ¬ ∃ x, P x ∧ Q x := 
    assume H1 : ∃ x, P x ∧ Q x, 
    show false, 
    from exists.elim 
            H1
            (assume a : U, 
             assume Hpq : P a ∧ Q a,
             have Hpa : P a, 
                from and.elim_left Hpq,
             have Hpqa : P a → ¬ Q a, 
                from H a,
             have Hnq : ¬ Q a, 
                from Hpqa Hpa, 
             have Hqa : Q a,
                from and.elim_right Hpq,
             show false, from Hnq Hqa).