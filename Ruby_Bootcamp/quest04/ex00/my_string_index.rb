def my_string_index(param_1, param_2)
    for i in 0..param_1.length
        if param_1[i] == param_2
            return i
        end
    end
    return -1
end